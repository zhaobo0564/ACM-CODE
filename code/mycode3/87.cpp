
create table books(
bookid int identity(1,1)primary key,
bookname varchar(100),
price float,
year_sales int
)

create table books_sales(
order_num int identity(001,1) primary key,
store_id char(4),
ord_date date,
qty int,
book_id int
)

drop table books
drop table booksales


insert books(bookname,price,year_sales) values('数据库系统',39,22)
insert books(bookname,price,year_sales) values('操作系统原理',40,1)

insert books_sales(store_id,ord_date,qty,book_id)  values('S01',GETDATE(),2,1)
insert books_sales(store_id,ord_date,qty,book_id)  values('S02',GETDATE(),1,1)
insert books_sales(store_id,ord_date,qty,book_id)  values('S03',GETDATE(),1,2)

--insert
create trigger book_insert
on books_sales
for insert
as
declare @book_id nchar(10)
select @book_id=book_id from inserted 
update books
set year_sales =year_sales +(
select qty
from inserted
where books.bookid=inserted.book_id
)
where books.bookid=@book_id
--drop insert
drop trigger book_insert


create trigger book_delete
on books_sales
for delete
as
declare @book_id nchar(10)
select @book_id=book_id from deleted 
update books
set year_sales =year_sales -(
select qty
from deleted
where books.bookid=deleted.book_id
)
where books.bookid=@book_id
--drop
drop trigger book_delete

insert books_sales(store_id,ord_date,qty,book_id)  values('S04',GETDATE(),1,2)
delete from books_sales where order_num=11


select * from books
select * from books_sales