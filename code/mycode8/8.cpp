P137
Index.jsp:
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE HTML>
<html>
<head>
<meta charset="utf-8">
<title>ʹ��request�����ȡ�������ֵ</title>
</head>
<body>
<a href="deal.jsp?id=1&user=">����ҳ</a>
</body>
</html>

deal.jsp:
<%@ page language="java" contentType="text/html; charset=UTF-8"
   pageEncoding="UTF-8"%>
<%
   String id = request.getParameter("id"); //��ȡid������ֵ
   String user = request.getParameter("user");//��ȡuser������ֵ
   String pwd = request.getParameter("pwd");//��ȡpwd����ֵ
%>
<!DOCTYPE HTML>
<html>
<head>
<meta charset="utf-8">
<title>����ҳ</title>
</head>
<body>
   id������ֵΪ��<%=id%><br> user������ֵΪ��<%=user%><br> pwd������ֵΪ��<%=pwd%>
</body>
</html>
P139
Index.jsp:
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE HTML>
<html>
<head>
<meta charset="utf-8">
<title>�����쳣ҳ��</title>
</head>
<body>
<%
try{                                       //�����쳣��Ϣ
   int money=100;
   int number=0;
   request.setAttribute("result",money/number);            //����ִ�н��
}catch(Exception e){
   request.setAttribute("result","�ܱ�Ǹ��ҳ���������");     //���������ʾ��Ϣ
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
<title>���ҳ</title>
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
<title>ͨ��cookie���沢��ȡ�û���¼��Ϣ</title>
</head>
<body>
<%
   Cookie[] cookies = request.getCookies();   //��request�л��Cookie����ļ���
   String user = "";                       //��¼�û�
   String date = "";                       //ע���ʱ��
   if (cookies != null) {
      for (int i = 0; i < cookies.length; i++) {    //����cookie����ļ���
         //���cookie���������ΪmrCookie
         if (cookies[i].getName().equals("mrCookie")) {
            //��ȡ�û���
            user = URLDecoder.decode(cookies[i].getValue().split("#")[0]);                date = cookies[i].getValue().split("#")[1];          //��ȡע��ʱ��
         }
      }
   }
   if ("".equals(user) && "".equals(date)) {              //���û��ע��
%>
      �ο����ã���ӭ�����ι��٣�<br><br>
      <form action="deal.jsp" method="post">
         ������������<input name="user" type="text" value="">
         <input type="submit" value="ȷ��">
      </form>
<%
   } else {                                       //�Ѿ�ע��
%>
      ��ӭ[<b><%=user %></b>]�ٴι���<br>
      ��ע���ʱ���ǣ�<%=date %>
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
<title>д��cookie</title>
</head>
<body>
<%
request.setCharacterEncoding("UTF-8");          //��������ı���ΪUTF-8
String user=URLEncoder.encode(request.getParameter("user"),"UTF-8");//��ȡ�û���
Cookie cookie = new Cookie("mrCookie", user+"#"+new java.util.Date().toLocaleString());//������ʵ����cookie����
cookie.setMaxAge(60*60*24*30);                   //����cookie��Ч��30��
response.addCookie(cookie);                      //����cookie
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
<title>��ҳ</title>
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
<title>�û���¼ҳ��</title>
</head>
<body>
<form name="form1" method="post" action="">
�û����� <input    name="name" type="text" id="name" style="width: 120px"><br>
��&nbsp;&nbsp;&nbsp;&nbsp;�룺 <input name="pwd" type="password" id="pwd" style="width: 120px"> <br>
<br>
<input type="submit" name="Submit" value="�ύ">
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
<title>Ӧ��application����ʵ����ҳ������</title>
</head>
<body>
<% 
int number=0;                       //����һ��������ʴ����ı���
if(application.getAttribute("number")==null){  //���û���һ�η���ʱ
   number=1;
}else{
   //��ȡapplication��Χ�ڵı�������ת��Ϊint��
   number=Integer.parseInt(application.getAttribute("number").toString());
   number=number+1;                     //�÷��ʴ�����1
}
out.print("���ǵ�"+number+"λ�����ߣ�");         //�����ǰ���ʴ���
//���µķ��ʴ������浽application��Χ�ڵ�������
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
<title>ʹ��exception�����ȡ�쳣��Ϣ</title>
</head>
<body>
<%
request.setAttribute("price","109.6Ԫ");    //���浥�۵�request��Χ�ڵı���price��
//��ȡ���ۣ���ת��Ϊfloat��
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
<title>������ʾҳ</title>
</head>
<body>
������ʾΪ��<%=exception.getMessage() %>
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
<title>�ڴ˴��������</title>
</head>
<body>
<form name="form1" method="post" action="deal.jsp">
�û���: <input     name="username" type="text" id="username" style="width:120px"><br>
��&nbsp;&nbsp;&nbsp;&nbsp;�룺<input name="pwd" type="password" id="pwd" style="width:120px"><br>
<br>
<input type="submit" name="Submit" value="�ύ">
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
<title>�ڴ˴��������</title>
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
<title>ϵͳ��ҳ</title>
</head>
<body>
���ã�[<%=username %>]��ӭ������!<br>
<a href="exit.jsp">[�˳�]</a>
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
<title>�ڴ˴��������</title>
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
<title>�û���¼</title>
<style type="text/css">
body{font-size: 12px;}
</style>
<script type="text/javascript">
	function mycheck() {
		if (form1.UserName.value == "") {//�ж��û����ǲ�Ϊ��
			alert("�������û�����");
			form1.UserName.focus();
			return;
		}
		if (form1.PWD.value == "") {//�ж������Ƿ�Ϊ��
			alert("���������룡");
			form1.PWD.focus();
			return;
		}
		if (form1.yanzheng.value == "") {//�ж���֤���Ƿ�Ϊ��
			alert("��������֤��!");
			form1.yanzheng.focus();
			return;
		}
		if (form1.yanzheng.value != form1.verifycode2.value) {//�ж���֤���Ƿ���ȷ
			alert("��������ȷ����֤��!!");
			form1.yanzheng.focus();
			return;
		}
		form1.submit();
	}
</script>
</head>
<body>
	<form name="form1" method="POST" action="check.jsp">
		�û����� <input name="UserName" type="text"><br><br>		<!-- �����û����ı���-->

		��&nbsp;&nbsp;&nbsp;&nbsp;�룺<input name="PWD" type="password"><br>	<br>	<!-- ���������ı��� -->
		��֤�룺<input name="yanzheng" type="text" 
			onKeyDown="if(event.keyCode==13){form1.Submit.focus();}" size="8">		<!-- ������֤���ı��� -->
		<%
			int intmethod = (int) ((((Math.random()) * 11)) - 1);
			int intmethod2 = (int) ((((Math.random()) * 11)) - 1);
			int intmethod3 = (int) ((((Math.random()) * 11)) - 1);
			int intmethod4 = (int) ((((Math.random()) * 11)) - 1);
			String intsum = intmethod + "" + intmethod2 + intmethod3 + intmethod4;
			//���õ����������������
		%>
		<input type="hidden" name="verifycode2" value="<%=intsum%>">	<!-- ����������,��������֤�Ƚ�-->
		<!-- ��ͼƬ������õ����������ͬ��ͼƬ��ʾ��ҳ����  --> 
		<img src="num/<%=intmethod%>.gif"> <img src="num/<%=intmethod2%>.gif"> 
		<img src="num/<%=intmethod3%>.gif"> <img src="num/<%=intmethod4%>.gif">
		<br><br>		
		<!-- �����ύ�����ð�ť-->
		<input name="Submit"
			type="button" class="submit1" value="��¼" onClick="mycheck()">
		&nbsp; <input name="Submit2" type="reset" class="submit1" value="����">
	</form>
</body>
</html>





check.jsp:
<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
   <%
    request.setCharacterEncoding("UTF-8");	//��������ı��룬���ڽ��������������
   	String name = request.getParameter("UserName");	//��ȡ�û�������
   	String password = request.getParameter("PWD");	//��ȡ�û�������������
   	String message ;
   	if(!request.getParameter("verifycode2").equals(request.getParameter("yanzheng"))){
   		message ="���������֤�벻��ȷ��";
   	}else if(name.equals("mr")&&(password.equals("mrsoft"))){	//�ж��û����������Ƿ�Ϸ�
   		message ="���Ե�¼ϵͳ��";
   	}else{
   		message ="�û������������";
   	}    	
    %>
    <script type="text/javascript">
    alert("<%=message%>")			
    window.location.href='index.jsp';
   </script>
