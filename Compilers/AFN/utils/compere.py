from os import name, system
from typing import Callable

title = """
                _                        _        
     /\        | |                      | |       
    /  \  _   _| |_ ___  _ __ ___   __ _| |_ __ _ 
   / /\ \| | | | __/ _ \| '_ ` _ \ / _` | __/ _` |
  / ____ \ |_| | || (_) | | | | | | (_| | || (_| |
 /_/    \_\__,_|\__\___/|_| |_| |_|\__,_|\__\__,_|
"""


def compere():
    """Compere.

    Displays on screen a nice title.

    """
    clear: Callable = lambda: system("clear")
    clear()
    print(title)
