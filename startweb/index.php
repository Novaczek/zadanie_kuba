<?php
require "app/config/d.b.php";
require "functions/templates/form.html.php";
if($_POST!=""){
$Imie = $_POST['Imie'];
$Nazwisko = $_POST['Nazwisko'];
$email = $_POST['email'];
$haslo = $_POST['haslo'];
}
$add="INSERT INTO users(id,user_name,user_surname,user_email,user_password,user_active) Values (NULL,$Imie,$Nazwisko,$email,$haslo,0)";
if($conn->query($add)){
    echo"uzytkownik zostal dodany";
}
?>
