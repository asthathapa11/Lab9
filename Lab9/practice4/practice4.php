<?php
    if(isset($_POST['submit'])) {
        $number = intval($_POST['number']);
        echo "<h2>Multiplication Table of $number</h2>";
        echo "<table border='1'>";
        echo "<tr><th>&nbsp;</th>";
        for($i=1; $i<=$number; $i++) {
            echo "<th>$i</th>";
        }
        echo "</tr>";
        for($i=1; $i<=$number; $i++) {
            echo "<tr>";
            echo "<th>$i</th>";
            for($j=1; $j<=$number; $j++) {
                echo "<td>" . ($i*$j) . "</td>";
            }
            echo "</tr>";
        }
        echo "</table>";
    }
?>