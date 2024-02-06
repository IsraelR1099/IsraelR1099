// edit.js
document.addEventListener('DOMContentLoaded', function () {
    const editForm = document.getElementById('editForm');
    const saveButton = document.getElementById('saveButton');

    editForm.addEventListener('submit', async function (event) {
        event.preventDefault();

        const email = document.getElementById('email').value;
        const username = document.getElementById('username').value;

        try {
		const userData = JSON.parse(localStorage.getItem('userData'));
		const token_access = JSON.parse(localStorage.getItem('token_access'));
		
		if (!userData || !token_access) {
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

	if (response.ok) {
		console.log('User data updated successfully.');
		window.location.href = 'user.html'; // Redirect to user page after successful update
	} else {
		console.error('Failed to update user data.');
	}
	} catch (error) {
		console.error('Error during update.', error);
	}
	});
});
