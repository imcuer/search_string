/*
 *  search_string.c
 *  Created on: 2018-7-19
 *  Author: MK
 *  usage:�����ַ���ƥ���㷨��ʵ�֣�Sunday��KMP��Boyer-Moore��horspool��
 */
#include<stdio.h>
#include<string.h>
#define maxNum 256
#define MAX(x, y) (x)>(y) ? (x):(y)
 //////////////////////////Sunday//////////////////////////////////////
void SundayPre(int sun_shift[], char* P, int lenP)
{
    int i;
    for (i = 0; i < maxNum; i++) {
        sun_shift[i] = lenP + 1;
    }
    // ģʽ��P��ÿ����ĸ���ֵ������±�
    // ����Ӧ����������ƥ�����ĩλ�ַ�����һλ�ַ��ƶ�����λ������Ҫ���ƶ�λ��
    for (i = 0; i < lenP; i++) {
        sun_shift[P[i]] = lenP - i;
    }
}
/*
function:
        Sunday�ַ�ƥ���㷨
Param:
@T �ı�����
@TLen �ı����ݳ���
@p ��Ҫƥ����ַ���
@lenP ��Ҫƥ����ַ�������
*/
char* Sunday(char* T, int lenT, char* P, int lenP, int shift[]) {
    // Ĭ��ֵ���ƶ�m+1λ
    int i;
    // ģʽ����ʼλ��������������
    int pos = 0;
    //printf("Sunday pos %d\n",pos);
    //ģʽ���Ѿ�ƥ�䵽��λ��
    int j, count = 0;
    while (pos <= lenT - lenP) {
        j = 0;
        while (T[pos + j] == P[j] && j < lenP) j++;
        // ƥ��ɹ�
        if (j >= lenP) {
            //printf("Sunday Find it. the position is %d  jump %d time\n",pos,count);
            return &T[pos];
        }
        else {
            // �ҵ������е�ǰ��ģʽ��ƥ�����ĩ�ַ�����һ���ַ�
            // ��ģʽ���г�������λ��
            // ����Ҫ��(ģʽ��ĩβ+1)�ƶ�����λ�õĲ���
            //printf("Sunday current step: %d jump num: %d\n",count++,shift[T[pos+lenP]]);
            pos += shift[T[pos + lenP]];
            //count++;
            //printf("pos %d\n",pos);
        }
    }
    //printf("Sunday not Find. jump %d time\n",count);
    return NULL;
}

////////////////////////////////KMP//////////////////////////////////////////////
//�Ż������next ������
/*
function:
        KMP��next������⣨Ԥ����
Param:
@p ��Ҫƥ����ַ���
@next ��Ҫƥ����ַ�����Ӧ��next����
*/
void KMPPre(char* p, int KMP_next[])
{
    int pLen = strlen(p);
    KMP_next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < pLen - 1) {
        //p[k]��ʾǰ׺��p[j]��ʾ��׺  
        if (k == -1 || p[j] == p[k]) {
            ++j;
            ++k;
            if (p[j] != p[k])
                KMP_next[j] = k;
            else if (KMP_next[k] != -1)//����k��0�Ļ�������next[0]��-1��
                KMP_next[j] = KMP_next[k];
            else
                KMP_next[j] = 0;
        }
        else {
            k = KMP_next[k];
        }
    }
}
/*
function:
        KMP�ַ�ƥ���㷨
Param:
@s �ı�����
@sLen �ı����ݳ���
@p ��Ҫƥ����ַ���
@pLen ��Ҫƥ����ַ�������
@next[] ��������
*/
char* KmpSearch(char* s, int sLen, char* p, int pLen, int next[])
{
    int i = 0;
    int j = 0;
    while (i < sLen && j < pLen) {
        //�����j=-1�������ֻص���P���Ŀ�ͷ��һ���ַ�����Ϊnext[0]=-1�������ߵ�ǰ�ַ�ƥ��ɹ�����S[i]==P[j]��������i++��j++    
        if (j == -1 || s[i] == p[j]) {
            i++;
            j++;
        }
        else {
            //�����j!=-1���ҵ�ǰ�ַ�ƥ��ʧ�ܣ�����i����(��ǰs��ʧ��ĵط�)��j=next[j]    
            //next[j]��Ϊj����Ӧ��nextֵ����ʵ���Ǻ���������ͬǰ׺�ĵط�������PΪ"AFHKAFOIU"����next[6]=2,����7���ַ���O����ǰ�����ַ�"AF"(���塢�����ַ�)����ͬǰ׺"AF"(��һ�������ַ�))
            j = next[j];
        }
    }
    if (j == pLen) {
        return &s[i - j];
    }
    else {
        return NULL;
    }
}
////////////////////////////////////BoyerMoore//////////////////////////////////////
/*
function:
        ��⻵�ַ�����
Param:
@pattern ��Ҫƥ����ַ���
@bmBc ���ַ�����
@m ��Ҫƥ����ַ�������
@
*/
void PreBmBc(char* pattern, int m, int bmBc[])
{
    int i;
    for (i = 0; i < 256; i++) {//һ���ַ�ռ��λ����256���ַ����������ַ������ǵ�������ĳ�ʼ���ǽ������ַ�ʧ��ʱ���ƶ����붼��ֵΪm
        bmBc[i] = m;
    }
    for (i = 0; i < m - 1; i++) {//���ģʽ��pattern�д��ڵ�ÿһ���ַ��������������ҵģ������һ���ַ����ط����봮ĩβ�ľ��룬������ʧ��ʱ���ƶ��ľ���,��һ���������˳�ʼ����һЩ�ַ����ƶ�����
        bmBc[pattern[i]] = m - 1 - i;
    }
}
/*
function:
        �ɰ�ĺú�׺�������飨�ú�׺���ȣ���ⷽ��
Param:
@pattern ��Ҫƥ����ַ���
@suff �ú�׺��������
@m ��Ҫƥ����ַ�������
*/
void suffix_old(char* pattern, int m, int suff[])
{
    int i, j;
    suff[m - 1] = m;
    for (i = m - 2; i >= 0; i--) {
        j = i;
        while (j >= 0 && pattern[j] == pattern[m - 1 - i + j]) j--;
        suff[i] = i - j;
    }
}
/*
function:
        �°�ĺú�׺�������飨�ú�׺���ȣ���ⷽ��
Param:
@pattern ��Ҫƥ����ַ���
@suff �ú�׺��������
@m ��Ҫƥ����ַ�������
*/
void suffix(char* pattern, int m, int suff[]) {
    int f, g, i;
    suff[m - 1] = m;
    g = m - 1;
    for (i = m - 2; i >= 0; --i) {
        if (i > g && suff[i + m - 1 - f] < i - g)
            suff[i] = suff[i + m - 1 - f];
        else {
            if (i < g)
                g = i;
            f = i;
            while (g >= 0 && pattern[g] == pattern[g + m - 1 - f])
                --g;
            suff[i] = f - g;
        }
    }
}
/*
function:
        �ú�׺������ⷽ��
Param:
@pattern ��Ҫƥ����ַ���
@bmGs �ú�׺����
@m ��Ҫƥ����ַ�������
*/
void PreBmGs(char* pattern, int m, int bmGs[])
{
    int i, j;
    int suff[maxNum];
    // �����׺����
    suffix(pattern, m, suff);
    // ��ȫ����ֵΪm������Case3
    for (i = 0; i < m; i++) {
        bmGs[i] = m;
    }
    // Case2
    j = 0;
    for (i = m - 1; i >= 0; i--) {
        if (suff[i] == i + 1) {
            for (; j < m - 1 - i; j++) {
                if (bmGs[j] == m)
                    bmGs[j] = m - 1 - i;
            }
        }
    }
    // Case1
    for (i = 0; i <= m - 2; i++) {
        bmGs[m - 1 - suff[i]] = m - 1 - i;
    }
}
/*
function:
        Boyer-Moore�ַ�ƥ���㷨
Param:
@text �ı�����
@n �ı����ݳ���
@pattern ��Ҫƥ����ַ���
@m ��Ҫƥ����ַ�������
*/
char* BoyerMoore(char* text, int n, char* pattern, int m, int bmBc[], int bmGs[])
{
    int i, pos;

    pos = 0;
    while (pos <= n - m) {
        for (i = m - 1; i >= 0 && pattern[i] == text[i + pos]; i--);
        if (i < 0) {
            return &text[pos];
        }
        else {
            pos += MAX(bmBc[text[i + pos]] - m + 1 + i, bmGs[i]);
        }
    }
    return NULL;
}
//////////////////////////horspool////////////////////////////////
/*
function:horspool�ַ�ƥ����Ԥ����
Param:
@P ��Ҫƥ����ַ���
@lenP ��Ҫƥ����ַ�������
*/
void horspoolPre(int hors_d[], char* P, int lenP)
{
    int i;
    for (i = 0; i < maxNum; i++) {
        hors_d[i] = lenP;
    }
    for (i = 0; i < (lenP - 1); i++) {
        hors_d[P[i]] = lenP - i - 1;
    }
}
/*
function:horspool�ַ�ƥ���㷨
Param:
@T �ı�����
@lenT �ı����ݳ���
@P ��Ҫƥ����ַ���
@lenP ��Ҫƥ����ַ�������
@hors_d[] ��������
*/
char* horspool(char* T, int lenT, char* P, int lenP, int hors_d[])
{
    int i, pos, j;
    pos = 0;
    while (pos <= (lenT - lenP)) {
        j = lenP - 1;
        while (j >= 0 && T[pos + j] == P[j]) j--;
        if (j == -1) {
            return &T[pos];
        }
        else {
            pos += hors_d[T[pos + lenP - 1]];
        }
    }
    return NULL;
}
