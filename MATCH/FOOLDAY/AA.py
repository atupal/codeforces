s = '''
George Washington, 1789-1797
John Adams, 1797-1801
Thomas Jefferson, 1801-1809
James Madison, 1809-1817
James Monroe, 1817-1825
John Quincy Adams, 1825-1829
Andrew Jackson, 1829-1837
Martin Van Buren, 1837-1841
William Henry Harrison, 1841
John Tyler, 1841-1845
James Knox Polk, 1845-1849
Zachary Taylor, 1849-1850
Millard Fillmore, 1850-1853
Franklin Pierce, 1853-1857
James Buchanan, 1857-1861
Abraham Lincoln, 1861-1865
Andrew Johnson, 1865-1869
Ulysses S. Grant, 1869-1877
Rutherford Birchard Hayes, 1877-1881
James Abram Garfield, 1881
Chester Alan Arthur, 1881-1885
Grover Cleveland, 1885-1889
Benjamin Harrison, 1889-1893
Grover Cleveland, 1893-1897
William McKinley, 1897-1901
Theodore Roosevelt, 1901-1909
William Howard Taft, 1909-1913
Woodrow Wilson, 1913-1921
Warren Gamaliel Harding, 1921-1923
Calvin Coolidge, 1923-1929
Herbert Clark Hoover, 1929-1933
Franklin Delano Roosevelt, 1933-1945
Harry S. Truman, 1945-1953
Dwight David Eisenhower, 1953-1961
John Fitzgerald Kennedy, 1961-1963
Lyndon Baines Johnson, 1963-1969
Richard Milhous Nixon, 1969-1974
Gerald Rudolph Ford, 1974-1977
James Earl Carter, Jr., 1977-1981
Ronald Wilson Reagan, 1981-1989
George Herbert Walker Bush, 1989-1993
William Jefferson Clinton, 1993-2001
George Walker Bush, 2001-2009
Barack Hussein Obama, 2009-'''

s = s.split('\n')
for i in xrange(43):
    s[i + 1] = s[i + 1].split(',')[0]

i = raw_input()
i = int(i)

if i == 8:
    print 'Van Buren'
else:
    print s[i].split(' ')[len(s[i].split(' ')) - 1]
