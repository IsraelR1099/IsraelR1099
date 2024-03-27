import { 'fetchAccountData' } from './fetchUser.js';

document.addEventListener('DOMContentLoaded', function() {
	const oauthButton = document.getElementById('oauthButton');
	if (oauthButton) {
		oauthButton.addEventListener('click', function() {
			// Redirect to the OAuth page
			window.location.href = 'https://api.intra.42.fr/oauth/authorize?client_id=u-s4t2ud-e874bdccc7b9faba51dfa57e391ee107a6d1eb6f84e62ddd20679af8403c851b&redirect_uri=https%3A%2F%2Fpong.xyz%2Fprofile&response_type=code';
		});
	}

	const getUrlParameter = (name) => {
	name = name.replace(/[\[]/, '\\[').replace(/[\]]/, '\\]');
	const regex = new RegExp('[\\?&]' + name + '=([^&#]*)');
	const results = regex.exec(location.search);
	return results === null ? '' : decodeURIComponent(results[1].replace(/\+/g, ' '));
	};

	authCode();

	async function authCode()
	{
		const authCode = getUrlParameter('code');
		if (authCode)
		{
			try {
				const response = await fetch('/api/user/auth42/', {
					method: 'POST',
					headers: {
						'Content-Type': 'application/json',
					},
					body: JSON.stringify({ "code": authCode }),
				});
				const data = await response.json();
				if (response.ok)
				{
					console.log("Auth success");
					localStorage.setItem('userData', JSON.stringify(data));
					await fetchAccountData(data.id);
				}
				else
				{
					console.error("Failed to authenticate:", data.error);
					alert("Failed to authenticate: " + data.error);
				}
			} catch (error) {
				console.error("Failed to authenticate:", error);
				alert("Failed to authenticate: " + error);
			}
		}
	}
});
