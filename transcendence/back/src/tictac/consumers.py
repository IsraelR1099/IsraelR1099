from channels.generic.websocket import WebsocketConsumer
from asgiref.sync import async_to_sync

import json
import logging


class GameRoom(WebsocketConsumer):
    def connect(self):
        try:
            self.room_name = self.scope['url_route']['kwargs']['room_code']
            self.room_group_name = 'room_%s' % self.room_name
            print(self.room_group_name)

            # Join room group
            async_to_sync(self.channel_layer.group_add)(
                    self.room_group_name,
                    self.channel_name
            )

            self.accept()
        except Exception as e:
            logging.error(f"Error connecting to websocket: {e}")

    def disconnect(self):
        try:
            async_to_sync(self.channel_layer.group_discard)(
                    self.room_group_name,
                    self.channel_name
            )
        except Exception as e:
            logging.error(f"Error disconnecting from websocket: {e}")

    def receive(self, text_data):
        try:
            print(text_data)
            async_to_sync(self.channel_layer.group_send)(
                    self.room_group_name, {
                        'type': 'run_game',
                        'message': text_data
                    }
            )
        except Exception as e:
            logging.error(f"Error receiving message from websocket: {e}")

    def run_game(self, event):
        data = event['message']
        data = json.loads(data)

        self.send(text_data=json.dumps({
            'message': data['message']
            }))
