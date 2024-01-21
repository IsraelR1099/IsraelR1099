document.addEventListener('DOMContentLoaded', function () {
    const loginForm = document.getElementById('loginForm');
    const registerForm = document.getElementById('registerForm');

    loginForm.addEventListener('submit', async function (event) {
        event.preventDefault();
        const email = document.getElementById('email').value;
        const password = document.getElementById('password').value;

        // Make a POST request to your Django login endpoint
	try {
		const response = await fetch('/api/user/login/', {
		    method: 'POST',
		    headers: {
			'Content-Type': 'application/json',
		    },
		    body: JSON.stringify({ email, password }),
		});
		const data = await response.json();

        // Handle the response as needed
		console.log(data);
	} catch (error) {
		console.error("there was an error", error);
	}
    });

    registerForm.addEventListener('submit', async function (event) {
        event.preventDefault();
        const newUsername = document.getElementById('newUsername').value;
        const newPassword = document.getElementById('newPassword').value;

        // Make a POST request to your Django register endpoint
	try {
		const response = await fetch('https://127.0.0.1:8000/api/user/register/', {
		    method: 'POST',
		    headers: {
			'Content-Type': 'application/json',
			'Accept': 'application/json'
		    },
		    body: JSON.stringify({ newUsername, newPassword }),
		});

		const data = await response.json();

        // Handle the response as needed
		console.log(data);
	} catch (error) {
		console.error(error);
	}
    });
});
