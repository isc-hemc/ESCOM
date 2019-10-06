from typing import Iterable, List, Optional


class AFN:
    """AFN class.

    Object that contains the information of an AFN.

    Attributes
    ----------
    states: List
        Finite set of states.
    alphabet: List
        Finite set of symbols.
    start_state: str
        State before any input been processed.
    accept_state: List
        Set of states.
    transitions: List
        Transition function, δ: Q × Σ → Q.

    """

    __slots__ = (
        "states",
        "alphabet",
        "start_state",
        "accept_states",
        "transitions",
        "_result",
        "_error",
    )

    def __init__(
        self,
        states: List,
        alphabet: List,
        start_state: str,
        accept_states: List,
        transitions: List,
    ):
        """Constructor."""
        self.states: List = states
        self.alphabet: List = alphabet
        self.start_state: str = start_state
        self.accept_states: List = accept_states
        self.transitions: List = transitions
        self._result: List = []
        self._error: str = "x"

    def _acceptation_paths(self) -> Iterable:
        """Accept Paths.

        Filter all the paths that finish in one of the `accept states` of the
        automaton.

        Returns
        -------
        List
            Acceptation paths.

        """
        return filter(lambda x: x[-1] in self.accept_states, self._result)

    def _filter_transitions(
        self, data: str, position: int, current: str
    ) -> List:
        """Obtain Transition Set.

        Gets the possible next transitions that the automaton can follow for
        the given input.

        Parameters
        ----------
        data: str
            Input to validate.
        position: int
            Pointer to the current position of the input.
        current: str
            Current state of the automaton in which the input is positioned.

        Returns
        -------
        List
            Transitions that the automaton can follow for the input in the
            current position.

        """
        return list(
            filter(
                lambda x: x[0] == current and data[position] == x[1],
                self.transitions,
            )
        )

    def validate(
        self,
        data: str,
        position: int = 0,
        path: List = [],
        current: Optional[str] = None,
    ) -> List:
        """Validate.

        Validates if a given input belongs to the automaton alphabet.

        Parameters
        ----------
        data: str
            Input to validate.
        position: int
            Pointer to the current position of the input.
        path: List
            Route that the automaton is generating for the input.
        current: optional, str
            Current state of the automaton in which the input is positioned.

        Returns
        -------
        List
            All posible routes that the automaton generate for the input.

        """
        current = self.start_state if current is None else current
        if len(data) < position + 1:
            path.append(current)
            self._result.append(path)
            return path
        transition_set = self._filter_transitions(data, position, current)
        if not transition_set:
            path.append(current)
            self.validate(data, position + 1, path.copy(), self._error)
        path.append(current)
        for t in transition_set:
            self.validate(data, position + 1, path.copy(), t[2])
        return self._result

    def display_acceptation_paths(self, data: str):
        """Display Acceptation Paths.

        Displays on console the acceptations paths for the evaluated input.

        Parameters
        ----------
        data: str
            Evaluated input.

        """
        print(f"\nEvaluated input: {data}\n\nPaths:\n")
        for path in self._acceptation_paths():
            aux: str = f"--> Q{path.pop(0)}"
            for state, symbol in zip(path, data):
                aux += f"({symbol}) --> Q{state}"
            print(aux)
