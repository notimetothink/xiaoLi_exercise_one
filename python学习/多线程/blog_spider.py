import requests
from bs4 import BeautifulSoup
# 列表推导式
urls = [
    f"https://www.cnblogs.com/#p{page}"
    for page in range(1, 50+1)
]

def craw(url):
    # 请求网页
    r = requests.get(url)
    # print(url, len(r.text))
    return r.text

def parse(html):
    # class="post-item-title"
    soup = BeautifulSoup(html, "html.parser")
    links = soup.find_all("a", class_="post-item-title")
    return [(link["href"], link.get_text()) for link in links]

if __name__ == "__main__":
    for result in parse(craw(urls[0])):
        print(result)