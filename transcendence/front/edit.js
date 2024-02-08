// edit.js
document.addEventListener('DOMContentLoaded', function () {
	const editForm = document.getElementById('editForm');
	const saveButton = document.getElementById('saveButton');

	editForm.addEventListener('submit', async function (event)
	{
		event.preventDefault();

		const email = document.getElementById('email').value;
		const username = document.getElementById('username').value;
		console.log ('email', email);
		console.log ('username', username);

		try
		{
			const userData = JSON.parse(localStorage.getItem('userData'));
			if (!userData || !userData.token_access)
			{
				console.error('No user data found.');
				return;
			}

			const response = await fetch(`/api/user/account/${userData.id}/edit/`, {
				method: 'POST',
				headers: {
					'Content-Type': 'application/json',
					'Accept': 'application/json',
					'Authorization': `Bearer ${userData.token_access}`,
				},
				body: JSON.stringify({ email, username }),
			});

			const data = await response.json();

			if (response.ok)
			{
				if (data.errors)
				{
					console.error('Failed to update user data.', data.error);
					alert('Failed to update user data.');
					return;
				}
				console.log('User data updated successfully.');
				await fetchAccountData(userData.id, userData.token_access, userData.token_refresh);
				window.location.href = 'user.html'; // Redirect to user page after successful update
			} else
			{
				console.error('Failed to update user data.');
			}
		} catch (error)
		{
			console.error('Error during update.', error);
		}
	});

	async function fetchAccountData(userId, token_access, token_refresh) {
		try {
			console.log('User ID:', userId);
			console.log('token access: ', token_access);
			const response = await fetch(`/api/user/account/${userId}/`, {
				method: 'GET',
				headers: {
					'Content-Type': 'application/json',
					'Accept': 'application/json',
					'Authorization': `Bearer ${token_access}`,
				},
			});

			const data = await response.json();
			if (response.ok) {
				localStorage.setItem('userData', JSON.stringify(data));
			} else {
				console.error('Failed to fetch account data');
			}

		} catch (error) {
			console.error(error);
		}
	}
});
