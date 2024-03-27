import { fetchAccountData } from './fetchUser.js';

document.addEventListener('DOMContentLoaded', function() {
	const registerForm = document.getElementById('registerForm');
	async function registerUser(email, username, password1, password2) {
		try {
			const response = await fetch('/api/user/register/', {
				method: 'POST',
				headers: {
					'Content-Type': 'application/json',
				},
				body: JSON.stringify({
					email,
					username,
					password1,
					password2,
				}),
			});

			const data = await response.json();
			if (response.ok) {
				console.log(data);
				localStorage.setItem('userData', JSON.stringify(data));
				await fetchAccountData(data.id);
			}
			else {
				console.error("Register failed: ", data.error);
			}
		} catch (error) {
			console.error('Error:', error);
		}
	}

	registerForm.addEventListener('submit', async function(event) {
		event.preventDefault();
		const email = document.getElementById('inputEmail').value;
		const username = document.getElementById('inputUsername').value;
		const password1 = document.getElementById('inputPassword1').value;
		const password2 = document.getElementById('inputPassword2').value;
		await registerUser(email, username, password1, password2);
	});
});
