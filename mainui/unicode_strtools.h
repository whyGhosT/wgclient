#pragma once
#ifndef UNICODE_STR_TOOLS_H
#define UNICODE_STR_TOOLS_H


#ifdef _WIN32

typedef wchar_t uchar16;
typedef unsigned int uchar32;

#else

typedef unsigned short uchar16;
typedef unsigned int uchar32;

#endif // _WIN32

enum EStringConvertErrorPolicy
{
	_STRINGCONVERTFLAG_SKIP = 1,
	_STRINGCONVERTFLAG_FAIL = 2,
	_STRINGCONVERTFLAG_ASSERT = 4,

	STRINGCONVERT_REPLACE = 0,
	STRINGCONVERT_SKIP = 1,
	STRINGCONVERT_FAIL = 2,

	STRINGCONVERT_ASSERT_REPLACE = 4,
	STRINGCONVERT_ASSERT_SKIP = 5,
	STRINGCONVERT_ASSERT_FAIL = 6,
};

bool Q_IsValidUChar32(uchar32 uVal);
int Q_UTF32ToUChar32(const uchar32 *pUTF32, uchar32 &uVal, bool &bErr);
int Q_UChar32ToUTF32Len(uchar32 uVal);
int Q_UChar32ToUTF32(uchar32 uVal, uchar32 *pUTF32);
int Q_UChar32ToUTF8Len(uchar32 uVal);
int Q_UChar32ToUTF16Len(uchar32 uVal);
int Q_UChar32ToUTF16(uchar32 uVal, uchar16 *pUTF16Out);
int Q_UChar32ToUTF8(uchar32 uVal, char *pUTF8Out);
int Q_UTF16ToUChar32(const uchar16 *pUTF16, uchar32 &uValueOut, bool &bErrorOut);
int Q_UTF8ToUTF16(const char *pUTF8, uchar16 *pUTF16, int cubDestSizeInBytes, EStringConvertErrorPolicy ePolicy);
int Q_UTF8ToUTF32(const char *pUTF8, uchar32 *pUTF32, int cubDestSizeInBytes, EStringConvertErrorPolicy ePolicy);
int Q_UTF16ToUTF8(const uchar16 *pUTF16, char *pUTF8, int cubDestSizeInBytes, EStringConvertErrorPolicy ePolicy);
int Q_UTF16ToUTF32(const uchar16 *pUTF16, uchar32 *pUTF32, int cubDestSizeInBytes, EStringConvertErrorPolicy ePolicy);
int Q_UTF32ToUTF8(const uchar32 *pUTF32, char *pUTF8, int cubDestSizeInBytes, EStringConvertErrorPolicy ePolicy);
int Q_UTF32ToUTF16(const uchar32 *pUTF32, uchar16 *pUTF16, int cubDestSizeInBytes, EStringConvertErrorPolicy ePolicy);
int Q_UTF8ToUChar32(const char *pUTF8_, uchar32 &uValueOut, bool &bErrorOut);
qboolean Q_UnicodeValidate(const char *pUTF8);
int Q_UnicodeLength(const char *pUTF8);
char *Q_UnicodeAdvance(char *pUTF8, int nChars);
//bool Q_IsMeanSpaceW(uchar16 wch);
bool Q_IsDeprecatedW(uchar16 wch);
uchar16 *StripUnprintableWorker(uchar16 *pwch, bool *pbStrippedAny);
qboolean Q_StripUnprintableAndSpace(char *pch);
qboolean V_UTF8ToUChar32(const char *pUTF8_, uchar32 *uValueOut);
int Q_UnicodeRepair(char *pUTF8);
wchar_t *Q_AdvanceSpace (wchar_t *start);
wchar_t *Q_ReadUToken (wchar_t *start, wchar_t *token, int tokenBufferSize, bool &quoted);

#endif // UNICODE_STR_TOOLS_H