document.addEventListener('DOMContentLoaded', function() {
	const queryParams = new URLSearchParams(window.location.search);

	const	creator = queryParams.get('creator');
	const	opponent = queryParams.get('opponent');
	const	room_code = queryParams.get('room_code');
	let	player = JSON.parse(localStorage.getItem('userData'));
	player = player.username;
	document.getElementById('player1Name').textContent = creator || 'Unknown';
	document.getElementById('player2Name').textContent = opponent || 'Unknown';
	let	websocket;
	let	gameState = [ "", "", "", "", "", "", "", "", "" ];
	let	elementArray = document.querySelectorAll('.cell');

	websocket = new WebSocket('wss://pong.xyz/api/ws/game/' + room_code + '/');
	elementArray.forEach(function (element) {
		element.addEventListener('click', function(event) {
			const cellId = event.target.id;
			let	value;
			console.log('player: ' + player + ' creator: ' + creator);
			if (player == creator ) {
				value = 'X';
			} else {
				value = 'O';
			}
			console.log('value before setText: ' + value);
			setText(cellId, value);
		})
	});

	function	setText(index, value) {
		console.log('Setting value: ' + value + ' at index: ' + index);
		var	data = {
			'index': index,
			'player': player,
		}
		if (gameState[parseInt(index)] == '') {
			gameState[parseInt(index)] = value;
			elementArray[parseInt(index)].innerHTML = value;
			websocket.send(JSON.stringify({
				data
			}));
		} else {
			alert('You cannot fill this cell');
		}
	}
	//22:00
	function	setAnotherUserText(index, value) {
		console.log('Setting value: ' + value + ' at index: ' + index);
		if (gameState[parseInt(index)] == '') {
			gameState[parseInt(index)] = value;
			elementArray[parseInt(index)].innerHTML = value;
		} else {
			alert('You cannot fill this cell');
		}
	}

	websocket.onopen = function(event) {
		console.log('Connected to the websocket server');
	}
	websocket.onmessage = function(event) {
		var	data = JSON.parse(event.data);
		setAnotherUserText(data.payload.index, data.payload.player);
		console.log('Message received: ' + event.data);
	}
	websocket.onclose = function(event) {
		console.log('Disconnected from the websocket server');
	}

});
