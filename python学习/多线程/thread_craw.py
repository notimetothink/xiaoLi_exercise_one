import blog_spider
import threading
import time

# 单线程爬取
def single_thread():
    print("single thread begin")
    for url in blog_spider.urls:
        blog_spider.craw(url)
    print("single thread end")

# 多线程爬取
def multi_thread():
    print("multi thread begin")
    # 创建线程
    threads = []
    for url in blog_spider.urls:
        # 创建线程对象
        threads.append(
            # args为参数，target为函数，args加逗号是因为只有一个参数，要保证是元组
            threading.Thread(target=blog_spider.craw, args=(url,))
        )
    # 启动线程
    for thread in threads:
        thread.start()
    # 等待线程结束
    for thread in threads:
        thread.join()
    print("multi thread end")

if __name__ == "__main__":
    start = time.time()
    single_thread()
    print(f"single thread cost {time.time() - start} seconds")
    start = time.time()
    multi_thread()
    print(f"multi thread cost {time.time() - start} seconds")