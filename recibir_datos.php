<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $dato = $_POST['dato'];
    echo "Dato recibido: " . $dato;
} else {
    echo "No se recibieron datos.";
}
?>
