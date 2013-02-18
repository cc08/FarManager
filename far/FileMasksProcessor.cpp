/*
FileMasksProcessor.cpp

����� ��� ������ � �������� ������� ������ (�� ����������� ������� �����
����������).
*/
/*
Copyright � 1996 Eugene Roshal
Copyright � 2000 Far Group
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:
1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.
3. The name of the authors may not be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "headers.hpp"
#pragma hdrstop

#include "FileMasksProcessor.hpp"
#include "processname.hpp"
#include "configdb.hpp"
#include "strmix.hpp"

FileMasksProcessor::FileMasksProcessor():
	BaseFileMask(),
	re(nullptr),
	m(nullptr),
	n(0),
	bRE(false)
{
}

void FileMasksProcessor::Free()
{
	Masks.Free();

	if (re)
		delete re;

	re = nullptr;

	if (m)
		xf_free(m);

	m = nullptr;
	n = 0;
	bRE = false;
}

/*
 �������������� ������ �����. ��������� ������, ����������� �������.
 ���������� FALSE ��� ������� (��������, ���� ��
 ����� ����� �� ����� ����� 0)
*/

bool FileMasksProcessor::Set(const string& masks, DWORD Flags)
{
	Free();

	string expmasks(masks);
	std::list<string> UsedGroups;
	for(;;)
	{

		size_t LBPos, RBPos;
		if(expmasks.Pos(LBPos, L'<') && expmasks.Pos(RBPos, L'>', LBPos))
		{
			string MaskGroupNameWB = expmasks.SubStr(LBPos, RBPos-LBPos+1);
			string MaskGroupName = expmasks.SubStr(LBPos+1, RBPos-LBPos-1);
			string MaskGroupValue;
			if (std::find(UsedGroups.begin(), UsedGroups.end(), MaskGroupName) == UsedGroups.end())
			{
				Global->Db->GeneralCfg()->GetValue(L"Masks", MaskGroupName, MaskGroupValue, L"");
				ReplaceStrings(expmasks, MaskGroupNameWB, MaskGroupValue);
				UsedGroups.push_back(MaskGroupName);
			}
		}
		else
			break;
	}

	size_t pos;
	const wchar_t* PathExtName = L"%PATHEXT%";
	if (expmasks.PosI(pos, PathExtName))
	{
		string strSysPathExt;
		UserDefinedList MaskList(ULF_UNIQUE);
		if (apiGetEnvironmentVariable(L"PATHEXT" ,strSysPathExt) && MaskList.Set(strSysPathExt))
		{
			string strFarPathExt;
			std::for_each(RANGE(MaskList, i)
			{
				strFarPathExt.Append('*').Append(i.Get()).Append(',');
			});
			strFarPathExt.SetLength(strFarPathExt.GetLength()-1);
			ReplaceStrings(expmasks, PathExtName, strFarPathExt, -1, true);
		}
	}

	bRE = expmasks.At(0) == L'/';

	if (bRE)
	{
		re = new RegExp;

		if (re && re->Compile(expmasks, OP_PERLSTYLE|OP_OPTIMIZE))
		{
			n = re->GetBracketsCount();
			m = (SMatch *)xf_malloc(n*sizeof(SMatch));

			if (!m)
			{
				n = 0;
				return false;
			}

			return true;
		}

		return false;
	}

	// ������������ ����� �������� �� ������ �������, �� � ����� � �������!
	DWORD flags=ULF_PACKASTERISKS|ULF_PROCESSBRACKETS|ULF_SORT|ULF_UNIQUE;

	Masks.SetParameters(flags, L",;");
	return Masks.Set(expmasks);
}

bool FileMasksProcessor::IsEmpty()
{
	if (bRE)
	{
		return !n;
	}

	return Masks.empty();
}

/* �������� ��� ����� �� ������� �����
   ���������� TRUE � ������ ������.
   ���� � ����� � FileName �� ������������ */
bool FileMasksProcessor::Compare(const string& FileName)
{
	if (bRE)
	{
		intptr_t i = n;
		size_t len = FileName.GetLength();
		bool ret = re->Search(FileName,FileName+len,m,i) ? TRUE : FALSE;

		//��������� ������ ���� ������� ������, ���� �� �������������.
		if (len > 1024)
			re->CleanStack();

		return ret;
	}

	FOR_RANGE(Masks, i)
	{
		// SkipPath=FALSE, �.�. � CFileMask ���������� PointToName
		if (CmpName(i->Get(), FileName, false))
			return true;
	}

	return false;
}
