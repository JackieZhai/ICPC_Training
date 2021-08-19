# -*- coding: utf-8 -*-
from bs4 import BeautifulSoup
import html5lib
from urllib.parse import urlencode
from urllib.request import Request, HTTPCookieProcessor, build_opener
from http.cookiejar import CookieJar
import json


class Vjudge:
    url = 'https://cn.vjudge.net'
    login_url = 'https://cn.vjudge.net/user/login'
    contest_login_url = 'https://cn.vjudge.net/contest/login/{cid}'
    contest_url = 'https://cn.vjudge.net/contest/{cid}'
    headers = {
        'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) '
                      'Ubuntu Chromium/52.0.2743.116 Chrome/52.0.2743.116 Safari/537.36',
        'Origin': "http://acm.hdu.edu.cn",
        'Host': "acm.hdu.edu.cn",
        'Content-Type': 'application/x-www-form-urlencoded',
        'Connection': 'keep-alive',
    }

    def __init__(self,contest_id, contest_password='', user_id='JackieZhai', password='zhaihao53724'):
        self.user_id = user_id
        self.password = password
        self.cid = contest_id
        self.cpwd = contest_password

        cookie = CookieJar()
        handler = HTTPCookieProcessor(cookie)
        self.opener = build_opener(handler)

    def login(self):
        data = {'username': self.user_id, 'password': self.password}
        post_data = urlencode(data).encode()
        request = Request(Vjudge.login_url, post_data, Vjudge.headers)
        response = self.opener.open(request).read()
        if str(response).find('success') > 0:
            return True
        else:
            print(response)
            return False

    def login_contest(self):
        
        url = Vjudge.contest_url.format(cid=self.cid)
        response = self.opener.open(url).read()
        if 'contest-login-form' in str(response):
            print('need login contest [{cid}].'.format(cid=self.cid))
            if not self.cpwd:
                self.cpwd = input("Password: ")
        else:
            return True
        url = Vjudge.contest_login_url.format(cid=self.cid)
        data = {'password': self.cpwd}
        post_data = urlencode(data).encode()
        request = Request(url, post_data, Vjudge.headers)
        response = self.opener.open(request).read()
        if 'error' in str(response):
            print(response)
            return False
        else:
            return True

    def get_problem_info(self, id, version):
        url = 'https://vjudge.net/problem/description/{publicDescId}?{publicDescVersion}'
        url = url.format(publicDescId=id, publicDescVersion=version)
        page = self.opener.open(url, timeout=7)
#        print(page.read())
        soup = BeautifulSoup(page, 'html5lib')
        desc = soup.find('div', {'class':'container', 'id': 'description-container'})
        headers = desc.find_all('dt')
        content = desc.find_all('dd')
        data = []
        for i in range(len(headers)):
            data.append({'title': headers[i].prettify(), 
                         'content': content[i].prettify()})
        return data
        # for item in json_data['sections']:
        #     print(item)
        #     print()

    def get_info(self):
        url = Vjudge.contest_url.format(cid=self.cid)
        request = Request(url)
        page = self.opener.open(request, timeout=5)
        soup = BeautifulSoup(page, 'html5lib')

        title = soup.find('h3').text.strip()
        print(title)

        table = soup.find('table', {'id': 'contest-problems'})
        table_body = table.find('tbody')
        rows = table_body.find_all('tr')
        data = []
        for row in rows:
            cols = row.find_all('td')
            cols = [ele.text.strip() for ele in cols]
            data.append([ele for ele in cols if ele])  # No need:Get rid of empty values

        n = len(data)
        print("total "+str(n)+" problems.")
        print("start crawler...")

        html_file = "A_winner_is_never_defeated_by_details" + ".html"

        f = open(html_file, 'w')
        f.write("""<!DOCTYPE html><html>
        <head><meta charset="UTF-8"><style media="print" type="text/css">.pageEnd{page-break-after:always;}
        </style><style>pre {white-space: pre-wrap;white-space: -moz-pre-wrap;white-space: -pre-wrap;white-space:
        -o-pre-wrap;word-wrap: break-word;}</style><title>""" + title + '</title></head><body>')

        purl = 'https://vjudge.net/contest/{pid}'.format(pid=self.cid)
        page = self.opener.open(purl, timeout=5)
        soup = BeautifulSoup(page, 'html5lib')
        print(soup)
        text_area = soup.find('textarea')
        json_data = json.loads(text_area.text)
        problem_data = json_data['problems']

        start = True
        for sub_data in problem_data:
            # print(sub_data)
            p_title = sub_data['num'] + ' - ' + sub_data['title']
            time_limit = sub_data['properties']['Time limit']
            memory_limit = sub_data['properties']['Memory limit']
            os = sub_data['properties']['OS'] if 'OS' in sub_data['properties'] else ''

            print(p_title + ' crawling...')
            problem_detail = self.get_problem_info(sub_data['publicDescId'], sub_data['publicDescVersion'])
            if not start:
                f.write('<div class="pageEnd"></div>')

            f.write('<div style="width:960px;margin:auto"><h1>' + p_title + '</h1></div>')
            f.write('<div style="width:960px;margin:auto"><span id="crawlSuccess" style="display: inline;" '
                    'class="crawlInfo"><b>Time Limit:</b><span id="timeLimit">'
                    + time_limit +
                    '</span>&nbsp;&nbsp;&nbsp;&nbsp;<b>Memory Limit:</b><span id="memoryLimit">'
                    + memory_limit +
                    '</span>&nbsp;&nbsp;&nbsp;&nbsp;<b>64bit IO Format:</b><span id="_64IOFormat">'
                    + os +
                    '</span></span></div><div style="width:960px;margin:auto">')

            for item in problem_detail:
                # print(type(item))
                # print(item)
                content = item['content']
                if content:
                    f.write('<div style="display: block;"><h2>' + item['title'] + '</h2><div class="textBG">'
                            + content + '</div></div>')

            start = False

        f.write('</body></html>')
        f.close()


if __name__ == '__main__':

    cid = input("Contest ID: ")
    # cid = 187775
    try:
        print('Initialization...')
        v = Vjudge(cid)
        print('User Login...')
        if v.login():
            print('Contest Login...')
            if v.login_contest():
                v.get_info()
            else:
                print('Login Contest Failed.')
        else:
            print('Login Vjudge Failed.')
    except Exception as e:
        print(e)
        print('please contact crazyX...')
