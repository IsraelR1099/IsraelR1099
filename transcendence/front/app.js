document.addEventListener('DOMContentLoaded', function () {
	const loginForm = document.getElementById('loginForm');
	const registerForm = document.getElementById('registerForm');
	const userPage = document.getElementById('userPage');

 	function redirectToUserPage(data) {
		localStorage.setItem('userData', JSON.stringify(data));
        	window.location.href = 'user.html';
    	}

    async function loginUser(username, password) {
        try {
            const response = await fetch('/api/user/login/', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                },
                body: JSON.stringify({ username, password }),
            });

            const data = await response.json();

            if (response.ok) {
                console.log(data);
                redirectToUserPage(data);
            } else {
                console.error("Login failed", data.error);
            }

        } catch (error) {
            console.error("There was an error", error);
        }
    }

    async function registerUser(email, username, password1, password2) {
        try {
            const response = await fetch('/api/user/register/', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                    'Accept': 'application/json',
                },
                body: JSON.stringify({ email, username, password1, password2 }),
            });

            const data = await response.json();

            if (response.ok) {
                console.log(data);
                redirectToUserPage(data);
            } else {
                console.error("Registration failed", data.error);
            }

        } catch (error) {
            console.error(error);
        }
    }

    loginForm.addEventListener('submit', async function (event) {
        event.preventDefault();
        const username = document.getElementById('username').value;
        const password = document.getElementById('password').value;

        await loginUser(username, password);
    });

    registerForm.addEventListener('submit', async function (event) {
        event.preventDefault();
        const email = document.getElementById('inputEmail').value;
        const username = document.getElementById('inputUsername').value;
        const password1 = document.getElementById('inputPassword1').value;
        const password2 = document.getElementById('inputPassword2').value;

        await registerUser(email, username, password1, password2);
    });
});
