<!DOCTYPE html>
<html>
    <head>
        <mate>
            <title>
                一个简单的jsp页面显示时间
            </title>

        </mate>
    </head>
    <body>
        <%
        Date date = new Date();
        SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH : mm:ss");
        String today = df.format(date)

        %>当前时间: <% = today %>
    </body>
</html>