create database Proyecto
use Proyecto
-- creamos una tabla donde estaran contenidos nuestros usuarios
create table Usuarios(
no_usuario int primary key identity (1,1),
nombre varchar(30) not null,
apellidos varchar(30),
c_plantas int not null
)

-- creamos una tabla para las plantas con la propia informacion de estas misas
create table Plantas(
no_usuario int,
foreign key (no_usuario) references Usuarios(no_usuario) on delete cascade on update cascade,
n_planta int primary key identity (1,1),
nombre_planta varchar(30) not null,
c_riegos int,
humedad_planta varchar(6) check (humedad_planta in ('humedo', 'seco')),
)

-- tabla donde se guardan todos los datos que nos regresaran nuestros sensores
create table DatosSensores(
id int primary key identity (1,1),
nombre_sensor varchar(30),
humedad_ambiental float(1),
temperatura_ambiental float(1),
)

select * from Usuarios
select * from Plantas
select * from DatosSensores