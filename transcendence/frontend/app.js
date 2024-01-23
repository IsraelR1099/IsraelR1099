document.addEventListener('DOMContentLoaded', function () {
    const loginForm = document.getElementById('loginForm');
    const registerForm = document.getElementById('registerForm');
	const userPage = document.getElementById('userPage');
	const logoutButton = document.getElementById('logoutButton');


	function redirectToUserPage() {
		loginForm.style.display = 'none';
		registerForm.style.display = 'none';
		userPage.style.display = 'block';
	}

	function handleLogout() {
		loginForm.style.display = 'block';
		registerForm.style.display = 'block';
		userPage.style.display = 'none';
	}

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

		if (response.ok) {
			console.log(data);
			redirectToUserPage();
		} else {
			console.error("Login failed", error);
		}

	} catch (error) {
		console.error("there was an error", error);
	}
    });


    registerForm.addEventListener('submit', async function (event) {
        event.preventDefault();
        const email = document.getElementById('inputEmail').value;
        const username = document.getElementById('inputUsername').value;
        const password1 = document.getElementById('inputPassword1').value;
        const password2 = document.getElementById('inputPassword2').value;

        // Make a POST request to your Django register endpoint
	try {
		const response = await fetch('/api/user/register/', {
		    method: 'POST',
		    headers: {
			'Content-Type': 'application/json',
			'Accept': 'application/json'
		    },
		    body: JSON.stringify({ email, username, password1, password2 }),
		});

		const data = await response.json();

		if (response.ok) {
			console.log(data);
			redirectToUserPage();
		}

	} catch (error) {
		console.error(error);
	}
    });

	logoutButton.addEventListener('click', function (event) {
		handleLogout();
	});
});
