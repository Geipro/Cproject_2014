#ifndef cmdH
#define cmdH

#define CC_FONT_BLACK     0   // ����
#define CC_FONT_GRAY      7   // ȸ��
#define CC_FONT_BLUE      9   // �Ķ�
#define CC_FONT_GREEN     10  // ���
#define CC_FONT_RED       12  // ����
#define CC_FONT_YELLOW    14  // ���
#define CC_FONT_WHITE     15  // ���

#define CC_BACK           0
#define CC_BACK_DBLUE     16
#define CC_BACK_DGREEN    32
#define CC_BACK_DRED      64
#define CC_BACK_DYELLOW   96
#define CC_BACK_DWHITE    112
#define CC_BACK_GRAY      128
#define CC_BACK_BLUE      144
#define CC_BACK_GREEN     160
#define CC_BACK_RED       192
#define CC_BACK_YELLOW    224
#define CC_BACK_WHITE     240


void textcolor(unsigned int text, unsigned int back);

#endif