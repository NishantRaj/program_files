import urllib2
from bs4 import BeautifulSoup

page = urllib2.urlopen("http://www.spoj-solutions.blogspot.com")
soup = BeautifulSoup(page)
print soup.prettify()
for incident in soup('td', width="90%"):
    where, linebreak, what = incident.contents[:3]
    print where.strip()
    print what.strip()