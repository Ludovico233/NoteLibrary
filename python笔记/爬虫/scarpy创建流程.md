1. 创建项目
	`scrapy  starproject  项目名称`

2. 进入项目
	`cd  项目名称`

3. 创建爬虫
	`scrapy  genspider  名字  域名`

4. 可能需要修改start_urls ，修改成你要抓取的那个页面

5. 对数据进行解析，在spider里面的 parse （response）方法中进行解析
```
def  parse(self,response):
		response.text  # 拿页面源代码
		response.xpath()
		response.cee()

		# 解析数据时，需要注意，默认xpath（）返回的是Selector对象
		# 想要数据必须使用 extract（） 提取shuj
		extrasct()  # 返回列表
		extract_first() # 返回一个数据

		yield 返回数据  -> 把数据交给pipeline来进行持久化存储
```

6. 在pipeline中完成数据的存储
	```
	class 类名()：
		def process_item(slef, item, spider):
			item: 数据
			spider: 爬虫
			return item  # 必须要 return 东西，否则下一个管道收不到数据
	
	```

7. 设置settings.py文件将pipeline进行生效设置
	```
	ITEM_PIPELINES = {
		'管道路径'：优先级   # 优先级数越小，优先级越高
	}
	```

8. 运行爬虫
	`scrapy  crawl 爬虫的名字`
	