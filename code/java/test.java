public class JDBCDTest {  
    public static void main(String[] args) throws Exception {  
        Connection conn = null;  
        String sql;  
        String url = "jdbc:mysql://localhost:3306/test?user=root&password=123&useUnicode=true&characterEncoding=UTF8";  
        try { 
            Class.forName("com.mysql.jdbc.Driver");// ��̬����mysql����  
            System.out.println("�ɹ�����MySQL��������");  
            conn = DriverManager.getConnection(url);  
            Statement stmt = conn.createStatement();  
            sql = "create table User(name varchar(20),password char(20),primary key(name))";  
            int result = stmt.executeUpdate(sql);// executeUpdate���᷵��һ����Ӱ����������������-1��û�гɹ�  
            if (result != -1) {  
                System.out.println("�������ݱ�ɹ�");  
                sql = "insert into User(name,password) values('С��','123456')";  
                result = stmt.executeUpdate(sql);  
                sql = "insert into User(name,password) values('admin','admin')";  
                result = stmt.executeUpdate(sql);  
                sql = "select * from User";  
                ResultSet rs = stmt.executeQuery(sql);// executeQuery�᷵�ؽ���ļ��ϣ����򷵻ؿ�ֵ  
                System.out.println("ѧ��\t����");  
                while (rs.next()) {  
                    System.out.println(rs.getString(1) + "\t" + rs.getString(2));// ��������ص���int���Ϳ�����getInt()  
                }  
            }  
        } catch (SQLException e) {  
            System.out.println("MySQL��������");  
            e.printStackTrace();  

        }
    }