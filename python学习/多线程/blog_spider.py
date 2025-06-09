import requests
# 列表推导式
urls = [
    f"https://www.cnblogs.com/#p{page}"
    for page in range(1, 50+1)
]

def craw(url):
    # 请求网页
    r = requests.get(url)
    print(url, len(r.text))

craw(urls[0])