<?php
    include "dataPerguntas.inc";

    if(isset($_GET["id"])){
        $id = $_GET["id"];
    } else $id = 0;

    if(isset($_POST["resposta"])){
        $opcaoEscolhida = $_POST["resposta"];
    } else $opcaoEscolhida = null;

    $carregaEnunciado = function($id) use ($enunciados){
        if(is_numeric($id) && $id < count($enunciados) && $id >= 0){
            echo "<strong>{$enunciados[$id]}</strong>";
        }
    };
    
    $carregaPergunta = function ($id) use ($alternativas,$keys){
        if(is_numeric($id) && $id < count($keys) && $id >= 0){
            $startForm = "<form action='verificaResposta.php' method='post'>";
            $endForm = "</form>";
            $submit = "<input type='submit' value='Enviar'>";
            $pergunta = $startForm;
            $hiddenID = "<input type='hidden' name='id' value='$id'>";

            foreach ($alternativas[$keys[$id]] as $chave => $alternativa) {
                $pergunta = $pergunta . "<input type='radio' id='$chave' name='resposta' value='$alternativa' required> ";
                $pergunta = $pergunta . "<label for='$chave'>$alternativa</label><br>";
            }
            $pergunta = $pergunta . $submit . $hiddenID . $endForm ;

            return $pergunta;
        }
    };

    $verificaResposta = function ($id) use ($alternativas, $respostas,$opcaoEscolhida){
        if($alternativas[$id][$respostas[$id]] == $opcaoEscolhida){
            return true;
        } else {
            false;
        }
    };

    $mostraFormsResposta = function ($id) use ($carregaPergunta, $carregaEnunciado){
        $carregaEnunciado($id) ;
        return $carregaPergunta($id);

    }

    //talvez use
    // function letraResposta($indice){
    //     $letra = array("A","B","C","D");
    //     return $letra[$indice];
    // }
?>