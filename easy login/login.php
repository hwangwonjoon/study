<?php

$id = $_POST["id"];
$pwd = $_POST["pwd"];

if($id == "abcd" && $pwd == "1234")
        printf("Login Success!!");
else
        printf("Login Fail!!");

?>
