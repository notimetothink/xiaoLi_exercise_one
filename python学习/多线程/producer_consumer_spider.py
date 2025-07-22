import queue
import blog_spider
import time
import random
import threading


def do_craw(url_queue: queue.Queue, html_queue: queue.Queue):
    while True:
        # 从 url_queue 中获取一个URL（如果队列为空，此处会阻塞等待）
        url = url_queue.get()
        # 请求网页 
        html = blog_spider.craw(url)
        # 将获取到的网页HTML内容放入 html_queue 队列中
        html_queue.put(html)
        # 打印当前线程信息和操作状态：
        # 1. threading.current_thread().name - 当前线程名称
        # 2. f"craw {url}" - 正在爬取的URL
        # 3. "url_queue.size=" - 当前队列大小
        # 4. url_queue.qsize() - 获取url_queue队列中剩余的任务数量
        print(threading.current_thread().name, f"craw {url}", "url_queue.size=", url_queue.qsize())
        # 随机休眠1-2秒，模拟人类操作间隔
        # 避免请求过于频繁导致被目标网站封禁
        time.sleep(random.randint(1, 2))
def do_parse(html_queue: queue.Queue, fout):
    while True:
        # 从 html_queue 队列中获取一个网页HTML内容（如果队列为空，此处会阻塞等待）
        html = html_queue.get()
        # 解析网页内容
        results = blog_spider.parse(html)
        # 将解析结果写入文件
        for result in results:
            fout.write(str(result) + "\n")
        # 打印当前线程信息和操作状态：
        # 1. threading.current_thread().name - 当前线程名称
        # 2. f"results.size {len(results)}" - 解析出的结果数量
        # 3. "html_queue.size=" - 当前队列大小
        # 4. html_queue.qsize() - 获取html_queue队列中剩余的任务数量
        print(threading.current_thread().name, f"results.size {len(results)}", "html_queue.size=", html_queue.qsize())
        time.sleep(random.randint(1, 2))

if __name__ == "__main__":
    # 创建一个队列，用于存储待爬取的URL
    url_queue = queue.Queue()
    # 创建一个队列，用于存储爬取到的网页HTML内容
    html_queue = queue.Queue()
    for url in blog_spider.urls:
        url_queue.put(url)

    for idx in range(3):
        t = threading.Thread(target=do_craw, args=(url_queue, html_queue), name=f"craw_thread{idx}")
        t.start()
    fout = open("data.txt", "w")
    for idx in range(2):
        t = threading.Thread(target=do_parse, args=(html_queue, fout), name=f"parse_thread{idx}")
        t.start()
    