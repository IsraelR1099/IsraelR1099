document.addEventListener('DOMContentLoaded', function() {
	const queryParams = new URLSearchParams(window.location.search);

	const	creator = queryParams.get('creator');
	const	opponent = queryParams.get('opponent');

	document.getElementById('player1Name').textContent = creator || 'Unknown';
	document.getElementById('player2Name').textContent = opponent || 'Unknown';
});
