async function fetchAccountData(userId) {
	try {
		console.log('User ID:', userId);
		const response = await fetch(`/api/user/account/${userId}/`, {
			method: 'GET',
			headers: {
			'Content-Type': 'application/json',
			'Accept': 'application/json'
			},
		});
		const data = await response.json();
		if (response.ok) {
			console.log("Account data fetched");
			redirectToUserPage(data);
		}
		else {
			console.error("Failed to feth account", data.error);
			alert("Failed to fetch user info.");
		}
	}
	catch (error) {
		console.error("error fetching user info:", error);
	}
}

export { fetchAccountData };
