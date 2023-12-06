from django.shortcuts import render
from django import forms

# Create your views here.
tasks = ["foo", "bar", "baz"]

def index(request):
    return (render(request, "tasks/index.html", {
        "tasks": tasks
        }))

def add(request):
    return (render(request, "tasks/add.html"))
