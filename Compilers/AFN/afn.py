from typing import List


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
        "result",
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
        self.result: List = []

    def validate(
        self, data: str, position: int = 0, path: List = [], current: str = "0"
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
        current: str
            Current state of the automaton in which the input is positioned.

        Returns
        -------
        List
            All posible routes that the automaton generate for the input.

        """
        if len(data) < position + 1:
            path.append(current)
            self.result.append(path)
            return path
        transition_set = self._obtain_transitions(data, position, current)
        if not transition_set:
            path.append(current)
            self.validate(data, position + 1, path.copy(), "x")
        path.append(current)
        for t in transition_set:
            self.validate(data, position + 1, path.copy(), t[2])
        return self.result

    def _obtain_transitions(
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
