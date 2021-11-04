<?php 
    include "perguntas.inc";

    $id = $_POST['id'] + 1;
    $pontuaçãoMaxima = $getPontuacaoMaxima();
    
    if ($verificaResposta($_POST['id']) && $id < $pontuaçãoMaxima){
        header ("location: http://localhost/ShowDoBilhao/perguntinha.php?id=$id"); 
    } else if ($verificaResposta($_POST['id'])){
        header ("location: http://localhost/ShowDoBilhao/vitoria.html"); 
    } else header ("location: http://localhost/ShowDoBilhao/derrota.html"); 
     
    
?>