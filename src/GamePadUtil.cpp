/****************************************************************************/
/*! @file
@brief 

-----------------------------------------------------------------------------
	Copyright (C) 2008 Takenori Imoto. All rights reserved.
	( http://www.kaede-software.com/ )
-----------------------------------------------------------------------------
@author		T.Imoto
@date		2008/01/21
@note

�\�[�X�R�[�h�`���ł���o�C�i���`���ł���A�ύX�̗L���Ɋւ�炸�A�ȉ��̏�����
��������ɂ����āA�Ĕz�z����юg�p�������܂�:

   1. �\�[�X�R�[�h�`���ōĔz�z����ꍇ�A��L���쌠�\���A�{����������щ��L�ӔC
      ����K���K���܂߂Ă��������B
   2. �o�C�i���`���ōĔz�z����ꍇ�A��L���쌠�\���A�{����������щ��L�ӔC����
      �K����A�z�z���ƂƂ��ɒ񋟂���镶������ё��̎����ɕK���܂߂Ă��������B

�{�\�t�g�E�F�A�͒��쌠�҂ɂ���āA�h����̂܂܁h�񋟂������̂Ƃ��܂��B�{�\�t
�g�E�F�A�ɂ��ẮA�����َ����킸�A���p�i�Ƃ��Ēʏ킻�Ȃ���ׂ��i�������Ȃ�
�Ă���Ƃ̕ۏ؂��A����̖ړI�ɓK������Ƃ̕ۏ؂��܂߁A���̕ۏ؂��Ȃ���܂���B
���R�̂�������킸�A���Q�����̌�����������킸�A���A�ӔC�̍������_��ł�
�邩���i�ӔC�ł��邩 (�ߎ����̑�) �s�@�s�ׂł��邩���킸�A���쌠�҂͉��ɂ���
�悤�ȑ��Q����������\����m�炳��Ă����Ƃ��Ă��A�{�\�t�g�E�F�A�̎g�p���甭
���������ڑ��Q�A�Ԑڑ��Q�A�����I�ȑ��Q�A���ʑ��Q�A�����I���Q�܂��͌��ʑ��Q�̂�
����ɑ΂��Ă� (��֕i�܂��� �T�[�r�X�̒�;�g�p�@��A�f�[�^�܂��͗��v�̑�����
�⏞; �܂��́A�Ɩ��̒��f�ɑ΂���⏞���܂�)�ӔC���������������܂���B

*****************************************************************************/

#include "GamePadUtil.h"
#include "GamePadLog.h"
#include <windows.h>
#include <vector>

namespace gamepad {

bool EncodeToUTF16( std::wstring &output, const std::string &source )
{
	int	len = ::MultiByteToWideChar( CP_ACP, 0, source.c_str(), -1, NULL, 0);
	std::vector<wchar_t> outbuf( len+1, 0 );
	int	ret = ::MultiByteToWideChar( CP_ACP, 0, source.c_str(), -1, &(outbuf[0]), len );
	if( ret ) {
		outbuf[ret] = L'\0';
		output = std::wstring( &(outbuf[0]) );
		return true;
	} else {
		Log( L"Failed to Call MultiByteToWideChar.", HRESULT_FROM_WIN32(GetLastError()) );
	}
	return false;
}

}; // namespace gamepad
