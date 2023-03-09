////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Begin license text.

Copyright 2023- MicomScript Project

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and 
associated documentation files (the �gSoftware�h), to deal in the Software without restriction, 
including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, 
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial 
portions of the Software.

THE SOFTWARE IS PROVIDED �gAS IS�h, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR 
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS 
IN THE SOFTWARE.

End license text.
*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
 * token.h
 */

#ifndef __TOKEN_H__

#define __TOKEN_H__

//�����ʃR�[�h
const int T_EOL			= 0; //�s��
const int T_Name		= 1; //���O
const int T_KeyWord		= 2; //�L�[���[�h
const int T_Integer		= 3; //����
const int T_Float		= 4; //����
const int T_Text		= 5; //������
const int T_ListWord	= 6; //List�p�L�[���[�h
const int T_Plus		=11; // +
const int T_Minus		=12; // -
const int T_Aster		=13; // *
const int T_Slash		=14; // /
const int T_Percent		=15; // %
const int T_Aster2		=16; // **
const int T_Plus2		=17; // ++
const int T_Minus2		=18; // --
const int T_Equal		=19; // =
const int T_PlusEQ		=20; // +=
const int T_MinusEQ		=21; // -=
const int T_AsterEQ		=22; // *=
const int T_SlashEQ		=23; // /=
const int T_PercentEQ	=24; // %=
const int T_Aster2EQ	=25; // **=
const int T_AndEQ		=26; // &=
const int T_OrEQ		=27; // |=
const int T_ExorEQ		=28; // ^=
const int T_TildeEQ		=29; // ~=
const int T_LShiftEQ	=30; // <<=
const int T_RShiftEQ	=31; // >>=
const int T_RShift2EQ	=32; // >>>=
const int T_And			=33; // &
const int T_Or			=34; // |
const int T_Exor		=35; // ^
const int T_Not			=36; // ~
const int T_LShift		=37; // <<
const int T_RShift		=38; // >>
const int T_RShift2		=39; // >>>
const int T_GT			=40; // >
const int T_GE			=41; // >=
const int T_LE			=42; // <=
const int T_LT			=43; // <
const int T_EQ			=44; // ==
const int T_NE			=45; // !=
const int T_LogicAnd	=46; // &&
const int T_LogicOr		=47; // ||
const int T_LogicNot	=48; // !
const int T_Question	=49; // ?
const int T_Colon		=50; // :
const int T_SemiColon	=51; // ;
const int T_LPar		=52; // (
const int T_RPar		=53; // )
const int T_LBracket	=54; // [
const int T_RBracket	=55; // ]
const int T_LCurly		=56; // {
const int T_RCurly		=57; // }
const int T_Dot			=58; // .
const int T_Comma		=59; // ,
const int T_Comment		=60; // �R�����g
const int T_Undef		=99; // ����`����


const int K_Var			= 1; // var
const int K_Function	= 2; // Function
const int K_Return		= 3; // return
const int K_Logic		= 4; // logic
const int K_If			= 5; // if
const int K_Else		= 6; // else
const int K_Do			= 7; // do
const int K_While		= 8; // while
const int K_For			= 9; // for
const int K_Times		=10; // times
const int K_Repeat		=11; // repeat
const int K_Break		=12; // break
const int K_Continue	=13; // continue
const int K_Match		=14; // switch
const int K_Case		=15; // case
const int K_Default		=16; // default
const int K_Foreach		=17; // foreach
//-------------------------------------------
const int K_Tree		=18; // tree
const int K_Exit		=19; // exit
const int K_VarList		=20; // varlist
const int K_ConList		=21; // conlist
const int K_FuncList	=22; // funclist
const int K_Undef		=23; // undef
const int K_Help		=24; // help
#ifdef T_ESP32
const int K_ESPCon		=25; // clist_ESP
//--------------------------------------------
//�t�@�C������R�}���h
const int K_Files		=26; // files
const int K_Save		=27; // save
const int K_Load		=28; // load
const int K_Show		=29; // show
const int K_Remove		=30; // remove
const int K_Rename		=31; // rename
const int K_Reset		=32; // reset
#endif

//--------------------------------------------

class Token {
protected:
	int		_code;		//�����ʃR�[�h
	int		_keyCode;	//�L�[�R�[�h
	long	_iValue	;	//����
	double	_fValue;	//���������_��
	char	*_string;	//���ʎq(���O)�A������

public:
	Token(int code);
	Token(int code, long value);
	Token(int code, double value);
	Token(int code, char *string);
	virtual ~Token();	//�f�X�g���N�^

	virtual void	clear();
	int				getCode();    //�����ʃR�[�h��Ԃ�
	long			getInteger();
	double			getFloat();   //���l��Ԃ��i���l�̏ꍇ�j
	int				getkeyCode(); //�L�[���[�h��Ԃ�
	char			*getString();
	void			print();      //�\��

};

class KeyWord : public Token {
private:

public:
	KeyWord(int keyCode) : Token(T_KeyWord) {
		_keyCode = keyCode;
	}

	void clear() {}
};

class Symbol : public Token {
private:

public:
	Symbol(int code) : Token(code) {}

	void clear() {}
};

#endif