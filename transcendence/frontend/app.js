document.addEventListener('DOMContentLoaded', function () {
    const loginForm = document.getElementById('loginForm');
    const registerForm = document.getElementById('registerForm');

    loginForm.addEventListener('submit', async function (event) {
        event.preventDefault();
        const username = document.getElementById('username').value;
        const password = document.getElementById('password').value;

        // Make a POST request to your Django login endpoint
        await fetch('https://127.0.0.1:8080/user/login/', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
            },
            body: JSON.stringify({ username, password }),
        });

        // Handle the response as needed
    });

    registerForm.addEventListener('submit', async function (event) {
        event.preventDefault();
        const newUsername = document.getElementById('newUsername').value;
        const newPassword = document.getElementById('newPassword').value;

        // Make a POST request to your Django register endpoint
        await fetch('https://127.0.0.1:8080/user/register/', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json',
		'Accept': 'application/json'
            },
            body: JSON.stringify({ newUsername, newPassword }),
        });

        // Handle the response as needed
    });
});
