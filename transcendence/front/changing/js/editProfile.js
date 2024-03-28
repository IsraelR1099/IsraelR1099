import { fetchAccountData } from './fetchUser.js';

document.addEventListener('DOMContentLoaded', function() {
	const editForm = document.getElementById('editForm');
	const editButton = document.getElementById('editButton');

	editForm.addEventListener('submit', async function(event) {
		event.preventDefault();
		const email = document.getElementById('email').value;
		const username = document.getElementById('username').value;
		const profileImageInput = document.getElementById('profileImage').value;
		const profileImage = profileImageInput.files[0];
		if (!profileImage) {
			return alert('Please select an image');
		}
		try {
			const userData = JSON.parse(localStorage.getItem('userData'));
			if (!userData) {
				return alert('Please log in');
			}
			const formData = new FormData();
			formData.append('email', email);
			formData.append('username', username);
			formData.append('profileImage', profileImage);
			const response = await fetch(`/api/user/account/${userData.id}/edit/`, {
				method: 'POST',
				headers: {
					'Content-Type': 'application/json',
					'Accept': 'application/json',
				},
				body: formData,
			});
			const data = await response.json();
			if (response.ok) {
				if (data.errors) {
					console.error('Faild to edit profile', data.errors);
					return alert('Faild to edit profile');
				}
				console.log('Profile edited', data);
				await fetchAccountData(userData.id);
				window.location.href = '../pages/user_profile.html';
			}
		} catch (error) {
			console.error('Faild to edit profile', error);
			alert('Faild to edit profile');
		}
	});
});

document.getElementById('editProfileButton').addEventListener('click', function() {
	window.location.href = '../pages/edit_profile.html';
});
