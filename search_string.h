/*
 *  search_string.h
 *  Created on: 2018-7-19
 *  Author: MK
 *  usage:�����ַ���ƥ���㷨��ʵ�֣�Sunday��KMP��Boyer-Moore��horspool��������
 */
#ifndef __SEARCH_CHA__
#define __SEARCH_CHA__
#include <stdio.h>
#include <string.h>
 //ƥ����ı�����  �����������Լ����ض��ַ�MY_TEST_string
char* My_TXT = "LOCALGX=%u6210%u90FD%7C%36%36%39%33%7C%u6210%u90FD%7C%36%36%39%33; Hm_lvt_e9e114d958ea263de46e080563e254c4=1531471439,1531472197,"
"1531537654,1531618652; BAIDUID=3ACF228CE89D0C2D28B1B3DA5C56C138:FG=1; Hm_lpvt_e9e114d958ea263de46e080563e254c4=1531629911;"
"BIDUPSID=C18478BCF075BCE0D2D0149D77980B8B; PSTM=1531620860; H_PS_PSSID=26523_1451_25810_21106_22159 Mozilla/5.0 (X11; Linux x86_64; rv:10.0.12)"
" Gecko/20130109 Firefox/10.0.12 http://news.baidu.com/mil AndroidDownloadManager/7.1.2 (Linux; U; Android 7.1.2; MI 5X Build/N2G47H)  http://switch.pcfg.cache."
"wpscdn.cn/wps_assets/cfg/ad/switch/load_bubblehttp://notify.wps.cn/notifyserver/notify?v=qidVrBsEjwqbMd%2F4ydmZ5CRKfbUlVq11EGkClTHeWH%2B5msXpw%2BQJC0oEFK%2FB8vu2bNj"
"aDZpcjl1wviBMWPHuYA==  http://tile-service.weather.microsoft.com/zh-CN/livetile/preinstall?region=CN&appid=C98EA5B0842DBB9405BBF071E1DA76512D21FE36&FORM=Threshold"
"http://res.res.res.res:80/"
"BIDUPSID=C18478BCF075BCE0D2D0149D77980B8B; PSTM=1531620860; H_PS_PSSID=26523_1451_25810_21106_22159 Mozilla/5.0 (X11; Linux x86_64; rv:10.0.12)"
" Gecko/20130109 Firefox/10.0.12 http://news.baidu.com/mil AndroidDownloadManager/7.1.2 (Linux; U; Android 7.1.2; MI 5X Build/N2G47H)  http://switch.pcfg.cache."
"wpscdn.cn/wps_assets/cfg/ad/switch/load_bubblehttp://notify.wps.cn/notifyserver/notify?v=qidVrBsEjwqbMd%2F4ydmZ5CRKfbUlVq11EGkClTHeWH%2B5msXpw%2BQJC0oEFK%2FB8vu2bNj"
"aDZpcjl1wviBMWPHuYA==  http://tile-service.weather.microsoft.com/zh-CN/livetile/preinstall?region=CN&appid=C98EA5B0842DBB9405BBF071E1DA76512D21FE36&FORM=Threshold"
"http://res.res.res.res:80/"
"BIDUPSID=C18478BCF075BCE0D2D0149D77980B8B; PSTM=1531620860; H_PS_PSSID=26523_1451_25810_21106_22159 Mozilla/5.0 (X11; Linux x86_64; rv:10.0.12)"
" Gecko/20130109 Firefox/10.0.12 http://news.baidu.com/mil AndroidDownloadManager/7.1.2 (Linux; U; Android 7.1.2; MI 5X Build/N2G47H)  http://switch.pcfg.cache."
"wpscdn.cn/wps_assets/cfg/ad/switch/load_bubblehttp://notify.wps.cn/notifyserver/notify?v=qidVrBsEjwqbMd%2F4ydmZ5CRKfbUlVq11EGkClTHeWH%2B5msXpw%2BQJC0oEFK%2FB8vu2bNj"
"aDZpcjl1wviBMWPHuYA==  http://tile-service.weather.microsoft.com/zh-CN/livetile/preinstall?region=CN&appid=C98EA5B0842DBB9405BBF071E1DA76512D21FE36&FORM=Threshold"
"http://res.res.res.res:80/"
"BIDUPSID=C18478BCF075BCE0D2D0149D77980B8B; PSTM=1531620860;MY_TEST_string H_PS_PSSID=26523_1451_25810_21106_22159 Mozilla/5.0 (X11; Linux x86_64; rv:10.0.12)"
" Gecko/20130109 Firefox/10.0.12 http://news.baidu.com/mil AndroidDownloadManager/7.1.2 (Linux; U; Android 7.1.2; MI 5X Build/N2G47H)  http://switch.pcfg.cache."
"wpscdn.cn/wps_assets/cfg/ad/switch/load_bubblehttp://notify.wps.cn/notifyserver/notify?v=qidVrBsEjwqbMd%2F4ydmZ5CRKfbUlVq11EGkClTHeWH%2B5msXpw%2BQJC0oEFK%2FB8vu2bNj"
"aDZpcjl1wviBMWPHuYA==  http://tile-service.weather.microsoft.com/zh-CN/livetile/preinstall?region=CN&appid=C98EA5B0842DBB9405BBF071E1DA76512D21FE36&FORM=Threshold"
"http://res.res.res.res:80/"
"BIDUPSID=C18478BCF075BCE0D2D0149D77980B8B; PSTM=1531620860; H_PS_PSSID=26523_1451_25810_21106_22159 Mozilla/5.0 (X11; Linux x86_64; rv:10.0.12)"
" Gecko/20130109 Firefox/10.0.12 http://news.baidu.com/mil AndroidDownloadManager/7.1.2 (Linux; U; Android 7.1.2; MI 5X Build/N2G47H)  http://switch.pcfg.cache."
"wpscdn.cn/wps_assets/cfg/ad/switch/load_bubblehttp://notify.wps.cn/notifyserver/notify?v=qidVrBsEjwqbMd%2F4ydmZ5CRKfbUlVq11EGkClTHeWH%2B5msXpw%2BQJC0oEFK%2FB8vu2bNj"
"aDZpcjl1wviBMWPHuYA==  http://tile-service.weather.microsoft.com/zh-CN/livetile/preinstall?region=CN&appid=C98EA5B0842DBB9405BBF071E1DA76512D21FE36&FORM=Threshold"
"http://res.res.res.res:80/"
"BIDUPSID=C18478BCF075BCE0D2D0149D77980B8B; PSTM=1531620860; H_PS_PSSID=26523_1451_25810_21106_22159 Mozilla/5.0 (X11; Linux x86_64; rv:10.0.12)"
" Gecko/20130109 Firefox/10.0.12 http://news.baidu.com/mil AndroidDownloadManager/7.1.2 (Linux; U; Android 7.1.2; MI 5X Build/N2G47H)  http://switch.pcfg.cache."
"wpscdn.cn/wps_assets/cfg/ad/switch/load_bubblehttp://notify.wps.cn/notifyserver/notify?v=qidVrBsEjwqbMd%2F4ydmZ5CRKfbUlVq11EGkClTHeWH%2B5msXpw%2BQJC0oEFK%2FB8vu2bNj"
"aDZpcjl1wviBMWPHuYA==  http://tile-service.weather.microsoft.com/zh-CN/livetile/preinstall?region=CN&appid=C98EA5B0842DBB9405BBF071E1DA76512D21FE36&FORM=Threshold"
"http://res.res.res.res:80/"
"BIDUPSID=C18478BCF075BCE0D2D0149D77980B8B; PSTM=1531620860; MY_TEST_MYringH_PS_PSSID=26523_1451_25810_21106_22159 Mozilla/5.0 (X11; Linux x86_64; rv:10.0.12)"
" Gecko/20130109 Firefox/10.0.12 http://news.baidu.com/mil AndroidDownloadManager/7.1.2 (Linux; U; Android 7.1.2; MI 5X Build/N2G47H)  http://switch.pcfg.cache."
"wpscdn.cn/wps_assets/cfg/ad/switch/load_bubblehttp://notify.wps.cn/notifyserver/notify?v=qidVrBsEjwqbMd%2F4ydmZ5CRKfbUlVq11EGkClTHeWH%2B5msXpw%2BQJC0oEFK%2FB8vu2bNj"
"aDZpcjl1wviBMWPHuYA==  http://tile-service.weather.microsoft.com/zh-CN/livetile/preinstall?region=CN&appid=C98EA5B0842DBB9405BBF071E1DA76512D21FE36&FORM=Threshold"
"http://res.res.res.res:80/"
"BIDUPSID=C18478BCF075BCE0D2D0149D77980B8B; PSTM=1531620860; H_PS_PSSID=26523_1451_25810_21106_22159 Mozilla/5.0 (X11; Linux x86_64; rv:10.0.12)"
" Gecko/20130109 Firefox/10.0.12 http://news.baidu.com/mil AndroidDownloadManager/7.1.2 (Linux; U; Android 7.1.2; MI 5X Build/N2G47H)  http://switch.pcfg.cache."
"wpscdn.cn/wps_assets/cfg/ad/switch/load_bubblehttp://notify.wps.cn/notifyserver/notify?v=qidVrBsEjwqbMd%2F4ydmZ5CRKfbUlVq11EGkClTHeWH%2B5msXpw%2BQJC0oEFK%2FB8vu2bNj"
"aDZpcjl1wviBMWPHuYA==  http://tile-service.weather.microsoft.com/zh-CN/livetile/preinstall?region=CN&appid=C98EA5B0842DBB9405BBF071E1DA76512D21FE36&FORM=Threshold"
"http://res.res.res.res:80/"
"BIDUPSID=C18478BCF075BCE0D2D0149D77980B8B; PSTM=1531620860; H_PS_PSSID=26523_1451_25810_21106_22159 Mozilla/5.0 (X11; Linux x86_64; rv:10.0.12)"
" Gecko/20130109 Firefox/10.0.12 http://news.baidu.com/mil AndroidDownloadManager/7.1.2 (Linux; U; Android 7.1.2; MI 5X Build/N2G47H)  http://switch.pcfg.cache."
"wpscdn.cn/wps_assets/cfg/ad/switch/load_bubblehttp://notify.wps.cn/notifyserver/notify?v=qidVrBsEjwqbMd%2F4ydmZ5CRKfbUlVq11EGkClTHeWH%2B5msXpw%2BQJC0oEFK%2FB8vu2bNj"
"aDZpcjl1wviBMWPHuYA==  http://tile-service.weather.microsoft.com/zh-CN/livetile/preinstall?region=CN&appid=C98EA5B0842DBB9405BBF071E1DA76512D21FE36&FORM=Threshold"
"http://res.res.res.res:80/"
"BIDUPSID=C18478BCF075BCE0D2D0149D77980B8B; PSTM=1531620860; H_PS_PSSID=26523_1451_25810_21106_22159 Mozilla/5.0 (X11; Linux x86_64; rv:10.0.12)"
" Gecko/20130109 Firefox/10.0.12 http://news.baidu.com/mil AndroidDownloadManager/7.1.2 (Linux; U; Android 7.1.2; MI 5X Build/N2G47H)  http://switch.pcfg.cache."
"wpscdn.cn/wps_assets/cfg/ad/switch/load_bubblehttp://notify.wps.cn/notifyserver/notify?v=qidVrBsEjwqbMd%2F4ydmZ5CRKfbUlVq11EGkClTHeWH%2B5msXpw%2BQJC0oEFK%2FB8vu2bNj"
"aDZpcjl1wviBMWPHuYA==  http://tile-service.weather.microsoft.com/zh-CN/livetile/preinstall?region=CN&appid=C98EA5B0842DBB9405BBF071E1DA76512D21FE36&FORM=Threshold"
"http://res.res.res.res:80/"
"BIDUPSID=C18478BCF075BCE0D2D0149D77980B8B; PSTM=1531620860; H_PS_PSSID=26523_1451_25810_21106_22159 Mozilla/5.0 (X11; Linux x86_64; rv:10.0.12)"
" Gecko/20130109 Firefox/10.0.12 http://news.baidu.com/mil AndroidDownloadManager/7.1.2 (Linux; U; Android 7.1.2; MI 5X Build/N2G47H)  http://switch.pcfg.cache."
"wpscdn.cn/wps_assets/cfg/ad/switch/load_bubblehttp://notify.wps.cn/notifyserver/notify?v=qidVrBsEjwqbMd%2F4ydmZ5CRKfbUlVq11EGkClTHeWH%2B5msXpw%2BQJC0oEFK%2FB8vu2bNj"
"aDZpcjl1wviBMWPHuYA==  http://tile-service.weather.microsoft.com/zh-CN/livetile/preinstall?region=CN&appid=C98EA5B0842DBB9405BBF071E1DA76512D21FE36&FORM=Threshold"
"http://res.res.res.res:80/" "BIDUPSID=C18478BCF075BCE0D2D0149D77980B8B; PSTM=1531620860; H_PS_PSSID=26523_1451_25810_21106_22159 Mozilla/5.0 (X11; Linux x86_64; rv:10.0.12)"
" Gecko/20130109 Firefox/10.0.12 http://news.baidu.com/mil AndroidDownloadManager/7.1.2 (Linux; U; Android 7.1.2; MI 5X Build/N2G47H)  http://switch.pcfg.cache."
"wpscdn.cn/wps_assets/cfg/ad/switch/load_bubblehttp://notify.wps.cn/notifyserver/notify?v=qidVrBsEjwqbMd%2F4ydmZ5CRKfbUlVq11EGkClTHeWH%2B5msXpw%2BQJC0oEFK%2FB8vu2bNj"
"aDZpcjl1wviBMWPHuYA==  http://tile-service.weather.microsoft.com/zh-CN/livetile/preinstall?region=CN&appid=C98EA5B0842DBB9405BBF071E1DA76512D21FE36&FORM=Threshold"
"http://res.res.res.res:80/" "BIDUPSID=C18478BCF075BCE0D2D0149D77980B8B; PSTM=1531620860; H_PS_PSSID=26523_1451_25810_21106_22159 Mozilla/5.0 (X11; Linux x86_64; rv:10.0.12)"
" Gecko/20130109 Firefox/10.0.12 http://news.baidu.com/mil AndroidDownloadManager/7.1.2 (Linux; U; Android 7.1.2; MI 5X Build/N2G47H)  http://switch.pcfg.cache."
"wpscdn.cn/wps_assets/cfg/ad/switch/load_bubblehttp://notify.wps.cn/notifyserver/notify?v=qidVrBsEjwqbMd%2F4ydmZ5CRKfbUlVq11EGkClTHeWH%2B5msXpw%2BQJC0oEFK%2FB8vu2bNj"
"aDZpcjl1wviBMWPHuYA==  http://tile-service.weather.microsoft.com/zh-CN/livetile/preinstall?region=CN&appid=C98EA5B0842DBB9405BBF071E1DA76512D21FE36&FORM=Threshold"
"http://res.res.res.res:80/" "BIDUPSID=C18478BCF075BCE0D2D0149D77980B8B; PSTM=1531620860; H_PS_PSSID=26523_1451_25810_21106_22159 Mozilla/5.0 (X11; Linux x86_64; rv:10.0.12)"
" Gecko/20130109 Firefox/10.0.12 http://news.baidu.com/mil AndroidDownloadManager/7.1.2 (Linux; U; Android 7.1.2; MI 5X Build/N2G47H)  http://switch.pcfg.cache."
"wpscdn.cn/wps_assets/cfg/ad/switch/load_bubblehttp://notify.wps.cn/notifyserver/notify?v=qidVrBsEjwqbMd%2F4ydmZ5CRKfbUlVq11EGkClTHeWH%2B5msXpw%2BQJC0oEFK%2FB8vu2bNj"
"aDZpcjl1wviBMWPHuYA==  http://tile-service.weather.microsoft.com/zh-CN/livetile/preinstall?region=CN&appid=C98EA5B0842DBB9405BBF071E1DA76512D21FE36&FORM=Threshold"
"http://res.res.res.res:80/";

//Ԥ����������
void SundayPre(int sun_shift[], char* P, int lenP);
void KMPPre(char* p, int KMP_next[]);
void PreBmBc(char* pattern, int m, int bmBc[]);
void PreBmGs(char* pattern, int m, int bmGs[]);
void horspoolPre(int hors_d[], char* P, int lenP);
/*
function:
		Sunday�ַ�ƥ���㷨
Param:
@T �ı�����
@TLen �ı����ݳ���
@p ��Ҫƥ����ַ���
@lenP ��Ҫƥ����ַ�������
*/
char* Sunday(char* T, int lenT, char* P, int lenP, int shift[]);
/*
function:
		KMP�ַ�ƥ���㷨
Param:
@s �ı�����
@sLen �ı����ݳ���
@p ��Ҫƥ����ַ���
@pLen ��Ҫƥ����ַ�������
*/
char* KmpSearch(char* s, int sLen, char* p, int pLen, int next[]);
/*
function:
		Boyer-Moore�ַ�ƥ���㷨
Param:
@text �ı�����
@n �ı����ݳ���
@pattern ��Ҫƥ����ַ���
@m ��Ҫƥ����ַ�������
*/
char* BoyerMoore(char* text, int n, char* pattern, int m, int bmBc[], int bmGs[]);
/*
function:
		horspool�ַ�ƥ���㷨
Param:
@T �ı�����
@lenT �ı����ݳ���
@P ��Ҫƥ����ַ���
@lenP ��Ҫƥ����ַ�������
*/
char* horspool(char* T, int lenT, char* P, int lenP, int hors_d[]);
#endif