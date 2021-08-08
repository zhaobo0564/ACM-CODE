P137
Index.jsp:
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE HTML>
<html>
<head>
<meta charset="utf-8">
<title>使用request对象获取请求参数值</title>
</head>
<body>
<a href="deal.jsp?id=1&user=">处理页</a>
</body>
</html>

deal.jsp:
<%@ page language="java" contentType="text/html; charset=UTF-8"
   pageEncoding="UTF-8"%>
<%
   String id = request.getParameter("id"); //获取id参数的值
   String user = request.getParameter("user");//获取user参数的值
   String pwd = request.getParameter("pwd");//获取pwd参数值
%>
<!DOCTYPE HTML>
<html>
<head>
<meta charset="utf-8">
<title>处理页</title>
</head>
<body>
   id参数的值为：<%=id%><br> user参数的值为：<%=user%><br> pwd参数的值为：<%=pwd%>
</body>
</html>
P139
Index.jsp:
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE HTML>
<html>
<head>
<meta charset="utf-8">
<title>捕获异常页面</title>
</head>
<body>
<%
try{                                       //捕获异常信息
   int money=100;
   int number=0;
   request.setAttribute("result",money/number);            //保存执行结果
}catch(Exception e){
   request.setAttribute("result","很抱歉，页面产生错误！");     //保存错误提示信息
}
%>
<jsp:forward page="deal.jsp"/>
</body>
</html>

deal.jsp:
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE HTML>
<html>
<head>
<meta charset="utf-8">
<title>结果页</title>
</head>
<body>
<%String message=request.getAttribute("result").toString(); %>
<%=message %>
</body>
</html>

P141
Index.jsp:
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.net.URLDecoder" %>
<!DOCTYPE HTML>
<html>
<head>
<meta charset="utf-8">
<title>通过cookie保存并读取用户登录信息</title>
</head>
<body>
<%
   Cookie[] cookies = request.getCookies();   //从request中获得Cookie对象的集合
   String user = "";                       //登录用户
   String date = "";                       //注册的时间
   if (cookies != null) {
      for (int i = 0; i < cookies.length; i++) {    //遍历cookie对象的集合
         //如果cookie对象的名称为mrCookie
         if (cookies[i].getName().equals("mrCookie")) {
            //获取用户名
            user = URLDecoder.decode(cookies[i].getValue().split("#")[0]);                date = cookies[i].getValue().split("#")[1];          //获取注册时间
         }
      }
   }
   if ("".equals(user) && "".equals(date)) {              //如果没有注册
%>
      游客您好，欢迎您初次光临！<br><br>
      <form action="deal.jsp" method="post">
         请输入姓名：<input name="user" type="text" value="">
         <input type="submit" value="确定">
      </form>
<%
   } else {                                       //已经注册
%>
      欢迎[<b><%=user %></b>]再次光临<br>
      您注册的时间是：<%=date %>
<%
   }
%>
</body>
</html>

deal.jsp:
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.net.URLEncoder" %>
<!DOCTYPE HTML>
<html>
<head>
<meta charset="utf-8">
<title>写入cookie</title>
</head>
<body>
<%
request.setCharacterEncoding("UTF-8");          //设置请求的编译为UTF-8
String user=URLEncoder.encode(request.getParameter("user"),"UTF-8");//获取用户名
Cookie cookie = new Cookie("mrCookie", user+"#"+new java.util.Date().toLocaleString());//创建并实例化cookie对象
cookie.setMaxAge(60*60*24*30);                   //设置cookie有效期30天
response.addCookie(cookie);                      //保存cookie
%>
<script type="text/javascript">window.location.href="index.jsp"</script>
</body>
</html>

P144
Index.jsp:
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE HTML>
<html>
<head>
<meta charset="utf-8">
<title>首页</title>
</head>
<body>
<%response.sendRedirect("login.jsp"); %>
</body>
</html>
login.jsp:
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE HTML>
<html>
<head>
<meta charset="utf-8">
<title>用户登录页面</title>
</head>
<body>
<form name="form1" method="post" action="">
用户名： <input    name="name" type="text" id="name" style="width: 120px"><br>
密&nbsp;&nbsp;&nbsp;&nbsp;码： <input name="pwd" type="password" id="pwd" style="width: 120px"> <br>
<br>
<input type="submit" name="Submit" value="提交">
</form>
</body>
</html>

P152
Index.jsp:
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE HTML>
<html>
<head>
<meta charset="utf-8">
<title>应用application对象实现网页计数器</title>
</head>
<body>
<% 
int number=0;                       //定义一个保存访问次数的变量
if(application.getAttribute("number")==null){  //当用户第一次访问时
   number=1;
}else{
   //获取application范围内的变量，并转换为int型
   number=Integer.parseInt(application.getAttribute("number").toString());
   number=number+1;                     //让访问次数加1
}
out.print("您是第"+number+"位访问者！");         //输出当前访问次数
//将新的访问次数保存到application范围内的属性中
application.setAttribute("number",number);
%>

</body>
</html>

P154
Index.jsp:
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" errorPage="error.jsp"%>
<!DOCTYPE HTML>
<html>
<head>
<meta charset="utf-8">
<title>使用exception对象获取异常信息</title>
</head>
<body>
<%
request.setAttribute("price","109.6元");    //保存单价到request范围内的变量price中
//获取单价，并转换为float型
float price=Float.parseFloat(request.getAttribute("price").toString());    
%>
</body>
</html>

error.jsp:
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" isErrorPage="true"%>
<!DOCTYPE HTML>
<html>
<head>
<meta charset="utf-8">
<title>错误提示页</title>
</head>
<body>
错误提示为：<%=exception.getMessage() %>
</body>
</html>

P155
Index.jsp:
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>在此处插入标题</title>
</head>
<body>
<form name="form1" method="post" action="deal.jsp">
用户名: <input     name="username" type="text" id="username" style="width:120px"><br>
密&nbsp;&nbsp;&nbsp;&nbsp;码：<input name="pwd" type="password" id="pwd" style="width:120px"><br>
<br>
<input type="submit" name="Submit" value="提交">
</form>
</body>
</html>




deal.jsp:
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    
<%
	String[][] userList={{"mr","mrsoft"},{"wgh","111"},{"sk","111"}};
	boolean flag=false;
	request.setCharacterEncoding("UTF-8");
	String username=request.getParameter("username");	
	String pwd=request.getParameter("pwd");
	for(int i=0;i<userList.length;i++){
		if(userList[i][0].equals(username)){
			if(userList[i][1].equals(pwd)){
				flag=true;
				break;
			}
		}
	}
	if(flag){
		session.setAttribute("username",username);
		response.sendRedirect("main.jsp");
	}else{
		response.sendRedirect("index.jsp");
	}
%>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>在此处插入标题</title>
</head>
<body>

</body>
</html>



main.jsp:
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%
	String username=(String)session.getAttribute("username");
%>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>系统主页</title>
</head>
<body>
您好！[<%=username %>]欢迎您访问!<br>
<a href="exit.jsp">[退出]</a>
</body>
</html>



exit.jsp:
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%
	session.invalidate();
	response.sendRedirect("index.jsp");
%>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>在此处插入标题</title>
</head>
<body>

</body>
</html>

P158
index.jsp:
<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE HTML>
<html>
<head>
<meta charset="utf-8">
<title>用户登录</title>
<style type="text/css">
body{font-size: 12px;}
</style>
<script type="text/javascript">
	function mycheck() {
		if (form1.UserName.value == "") {//判断用户名是不为空
			alert("请输入用户名！");
			form1.UserName.focus();
			return;
		}
		if (form1.PWD.value == "") {//判断密码是否为空
			alert("请输入密码！");
			form1.PWD.focus();
			return;
		}
		if (form1.yanzheng.value == "") {//判断验证码是否为空
			alert("请输入验证码!");
			form1.yanzheng.focus();
			return;
		}
		if (form1.yanzheng.value != form1.verifycode2.value) {//判断验证码是否正确
			alert("请输入正确的验证码!!");
			form1.yanzheng.focus();
			return;
		}
		form1.submit();
	}
</script>
</head>
<body>
	<form name="form1" method="POST" action="check.jsp">
		用户名： <input name="UserName" type="text"><br><br>		<!-- 设置用户名文本框-->

		密&nbsp;&nbsp;&nbsp;&nbsp;码：<input name="PWD" type="password"><br>	<br>	<!-- 设置密码文本框 -->
		验证码：<input name="yanzheng" type="text" 
			onKeyDown="if(event.keyCode==13){form1.Submit.focus();}" size="8">		<!-- 设置验证码文本框 -->
		<%
			int intmethod = (int) ((((Math.random()) * 11)) - 1);
			int intmethod2 = (int) ((((Math.random()) * 11)) - 1);
			int intmethod3 = (int) ((((Math.random()) * 11)) - 1);
			int intmethod4 = (int) ((((Math.random()) * 11)) - 1);
			String intsum = intmethod + "" + intmethod2 + intmethod3 + intmethod4;
			//将得到的随机数进行连接
		%>
		<input type="hidden" name="verifycode2" value="<%=intsum%>">	<!-- 设置隐藏域,用来做验证比较-->
		<!-- 将图片名称与得到的随机数相同的图片显示在页面上  --> 
		<img src="num/<%=intmethod%>.gif"> <img src="num/<%=intmethod2%>.gif"> 
		<img src="num/<%=intmethod3%>.gif"> <img src="num/<%=intmethod4%>.gif">
		<br><br>		
		<!-- 设置提交与重置按钮-->
		<input name="Submit"
			type="button" class="submit1" value="登录" onClick="mycheck()">
		&nbsp; <input name="Submit2" type="reset" class="submit1" value="重置">
	</form>
</body>
</html>





check.jsp:
<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
   <%
    request.setCharacterEncoding("UTF-8");	//设置请求的编码，用于解决中文乱码问题
   	String name = request.getParameter("UserName");	//获取用户名参数
   	String password = request.getParameter("PWD");	//获取用户输入的密码参数
   	String message ;
   	if(!request.getParameter("verifycode2").equals(request.getParameter("yanzheng"))){
   		message ="您输入的验证码不正确！";
   	}else if(name.equals("mr")&&(password.equals("mrsoft"))){	//判断用户名与密码是否合法
   		message ="可以登录系统！";
   	}else{
   		message ="用户名或密码错误！";
   	}    	
    %>
    <script type="text/javascript">
    alert("<%=message%>")			
    window.location.href='index.jsp';
   </script>
