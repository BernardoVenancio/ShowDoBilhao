<?php 
    include "perguntas.inc";

    $id = $_POST['id'] + 1;
    if($verificaResposta($_POST['id'])){
        header ("location: http://localhost/ShowDoBilhao/perguntinha.php?id=$id"); 
    } else header ("location: http://localhost/ShowDoBilhao/lose.html"); 
    

?>