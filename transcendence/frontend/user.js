document.addEventListener('DOMContentLoaded', function () {
	const logoutButton = document.getElementById('logoutButton');
	const userTable = document.getElementById('userTable');

	function handleLoginData() {
		const userData = JSON.parse(localStorage.getItem('userData'));

		if (userData) {
			const row = `
			<tr>
                <td>${userData.code}</td>
				<td>${userData.id}</td>
				<td>${userData.email}</td>
				<td>${userData.username}</td>
				<td>${userData.password}</td>
				<td>${userData.status}</td>
			</tr>
			`;
			userTable.innerHTML = row;
		}
	}

	async function logoutUser() {
		try {
			const response = await fetch('/api/user/logout/', {
				method: 'POST',
				headers: { 'Content-Type': 'application/json' },
			});

			if (response.ok) {
				localStorage.removeItem('userData');
        			window.location.href = 'index.html';
			}
			else {
				console.error('Failed to log out.');
			}
		} catch (error) {
			console.errror('Error during logout.', error);
		}
	}


 	logoutButton.addEventListener('click', async function (event) {
		event.preventDefault();
		await logoutUser();
    });

	handleLoginData();
});

// Assume you have a function to retrieve the user's email
// Replace getUserEmail() with the actual function to get the user's email
