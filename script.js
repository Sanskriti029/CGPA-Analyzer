function addCourse() {
    const div = document.createElement('div');
    div.classList.add('course');
    div.innerHTML = `
        <input type="text" name="grade[]" placeholder="Grade" required>
        <input type="number" name="credit[]" placeholder="Credits" required>
    `;
    document.getElementById('courses').appendChild(div);
}

document.getElementById('cgpaForm').addEventListener('submit', function(e) {
    e.preventDefault();

    const formData = new FormData(this);

    fetch('process.php', {
        method: 'POST',
        body: formData
    })
    .then(res => res.text())
    .then(data => {
        document.getElementById('result').innerText = `Your CGPA is: ${data}`;
    });
});