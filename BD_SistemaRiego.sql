create database Proyecto
use Proyecto
-- creamos una tabla donde estaran contenidos nuestros usuarios
create table Usuarios(
no_usuario int primary key identity (1,1),
nombre varchar(30) not null,
apellidos varchar(30),
c_plantas int not null,

)
-- creamos una tabla para las plantas con la propia informacion de estas misas
create table Plantas(
foreign key (no_usuario) references Usuarios(no_usuario) on delete cascade on update cascade

)