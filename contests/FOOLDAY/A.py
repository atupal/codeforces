#coding=utf-8

s = ''' 01、George Washington 乔治·华盛顿：1789-1797

02、John Adams 约翰·亚当斯：1797-1801

03、Thomas Jefferson托马斯·杰斐逊：1801-1809

04、James Madison 詹姆斯·麦迪逊：1809-1817

05、James Monroe 詹姆斯·门罗：1817-1825

06、John Quincy Adams约翰昆西·亚当斯：1825-1829

07、Andrew Jackson 安德鲁·杰克逊：1829-1837

08、Martin van Buren 马丁·范布伦：1837-1841

09、William Henry Harrison 威廉亨利·哈里森：1841-1841

10、John Tyler 约翰·泰勒：1841-1845

11、James K. Polk 詹姆斯·波尔克：1845-1849

12、Zachary Taylor 扎卡里·泰勒：1849-1850

13、Millard Fillmore 米勒德·菲尔莫尔：1850-1853

14、Franklin Pierce 富兰克林·皮尔斯：1853-1857

15、James Buchanan 詹姆斯·布坎南：1857-1861

16、Abraham Lincoln 亚伯拉罕·林肯：1861-1865

17、Andrew Johnson 安德鲁·约翰逊：1865-1869

18、Ulysses S. Grant 尤利塞斯·格兰特：1869-1877

19、Rutherford B. Hayes 拉塞福德·海斯：1877-1881

20、James A. Garfield 詹姆斯·加菲尔德：1881-1881

21、Chester A. Arthur 切斯特·阿瑟：1881-1885

22、Grover Cleveland 格罗弗·克利夫兰：1885-1889

23、Benjamin Harrison 本杰明·哈里森：1889-1893

24、Grover Cleveland 格罗弗·克利夫兰：1893-1897

25、William McKinley 威廉·麦金利：1897-1901

26、Theodore Roosevelt 西奥多·罗斯福：1901-1909

27、William H. Taft 威廉·塔夫脱：1909-1913

28、Woodrow Wilson 伍德罗·威尔逊：1913-1921

29、Warren G. Harding 沃伦·哈定：1921-1923

30、Calvin Coolidge 卡尔文·柯立芝：1923-1929

31、Herbert C. Hoover 赫泊特·胡佛：1929-1933

32、Franklin D. Roosevelt 富兰克林·罗斯福：1933-1945

33、Harry S. Truman 哈里·杜鲁门：1945-1953

34、Dwight D. Eisenhower德怀特·艾森豪威尔：1953-1961

35、John F. Kennedy 约翰·肯尼迪：1961-1963

36、Lyndon B. Johnson 林顿·约翰逊：1963-1969

37、Richard M. Nixon 理查德·尼克松：1969-1974

38、Gerald Ford 杰拉尔德·福特：1974-1977

39、Jimmy Carter 小詹姆斯·卡特：1977-1981

40、Ronald Reagan 罗纳德·里根：1981-1989

41、George Bush 乔治·布什：1989-1993

42、Bill Clinton 比尔·克林顿：1993-2001

43、George W. Bush 乔治·布什：2001-2008'''

import re

s = s.decode('utf-8')
s = s.split('\n')

import sys
for i in s:
    t = re.findall('[a-z A-Z.]{4,20}', i)
    if t != []:
        sys.stdout.write('"' + t[0]  + '"' +  ',')
