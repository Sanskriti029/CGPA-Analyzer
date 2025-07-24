<?php
$grades = $_POST['grade'];
$credits = $_POST['credit'];

// Prepare input.txt
$input = "";
for ($i = 0; $i < count($grades); $i++) {
    $input .= strtoupper(trim($grades[$i])) . " " . trim($credits[$i]) . "\n";
}
file_put_contents("input.txt", $input);

// Compile the C++ code (process.cpp → process.exe)
$compile_output = shell_exec("g++ process.cpp -o process.exe 2>&1");
if ($compile_output) {
    echo "C++ Compilation Error:\n" . $compile_output;
    exit;
}

// Run the compiled C++ program
$cgpa_output = shell_exec("process.exe 2>&1");
if (!$cgpa_output) {
    echo "Execution failed. Please check input or C++ code.";
    exit;
}

echo $cgpa_output;
?>
