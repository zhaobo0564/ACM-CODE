<!DOCTYPE html>
<html>
    <head>
        <mate>
            <title>
                һ���򵥵�jspҳ����ʾʱ��
            </title>

        </mate>
    </head>
    <body>
        <%
        Date date = new Date();
        SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH : mm:ss");
        String today = df.format(date)

        %>��ǰʱ��: <% = today %>
    </body>
</html>