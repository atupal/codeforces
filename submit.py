#!/usr/bin/env python2
"""
    submit.py
    ~~~~~~~~~

    author: atupal
    email: me@atupal.org

    submit code to codeforces
    usage:
      ./submit.py file_name
    file_name format: XXX_DIV1/name.xx
"""

import requests
import sys
import os
import time

from bs4 import BeautifulSoup

s = requests.Session()
try:
  with open('./user') as fi:
    user = fi.readline().strip()
    password= fi.readline().strip()
except:
  print 'read user file failed, use default username, password'
  user = 'atupal'
  password = ''

proxy_password = ''
http_proxy = {
    #'http': 'http://atupal:%s@j10.jayproxy.org:3000' % proxy_password
    }

def login():
  data = {
      }
  login_url = ''
  return
  r = s.post(login_url, data=data, allow_redirects=0)
  print r

def submit_code():
  contest_id = 493
  csrf_token = 'ff67ff20c5113064bd7af2dd46db36d0'
  submit_url = 'http://codeforces.com/contest/%d/submit?csrf_token=%s' % (contest_id, csrf_token)
  problem_id = 'E'
  lang = {
      'MSCPP': 2,
      }
  with open(sys.argv[1]) as fi:
    data = {
        'csrf_token': csrf_token,
        'action': 'submitSolutionFormSubmitted',
        'contestId': contest_id,
        'submittedProblemIndex': problem_id,
        'programTypeId': lang['MSCPP'],
        'source': fi.read(),
        'sourceFile': '',
        '_tta': 815,
    }
  

  headers = {
      'cookie': '''lastOnlineTimeUpdaterInvocation=1418047099368; JSESSIONID=5CBFFCCD53C3CC6400D6788412CB6E75-n1; 39ce7=CFiRm5rA; __utmt=1; lastOnlineTimeUpdaterInvocation=1418046915436; __utma=71512449.745827084.1418046889.1418046889.1418046889.1; __utmb=71512449.12.10.1418046889; __utmc=71512449; __utmz=71512449.1418046889.1.1.utmcsr=(direct)|utmccn=(direct)|utmcmd=(none)''',
      'referer': 'http://codeforces.com/contest/493/submit',
      'User-Agent': 'Chrome',
      }
  r = s.post(submit_url, proxies=http_proxy, data=data, headers=headers)
  print r

def colorful_print(text, color='red'):
  color_dict = {
      'red': '\033[31m',
      }
  print color_dict[color]+text+'\033[0m',


def fetch_result():
  while 1:
    try:
      pass
    except KeyboardInterrupt:
      exit(0)

def main():
  if len(sys.argv) > 1 and sys.argv[1].lower() != 'status':
    login()
    submit_code()
  fetch_result()

if __name__ == '__main__':
  login()
  #main()
