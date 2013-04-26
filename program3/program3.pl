husband(bob, alice).
husband(claude, dianna).
husband(keith, grace).
husband(edward, jennifer).
father(bob, edward).
father(bob, florence).
father(bob, grace).
father(keith, harry).
father(edward, iona).
brother(edward, florence).
brother(edward, florence).
brother(edward, florence).
brother(edward, grace).
brother(edward, grace).
brother(edward, grace).
brother(claude, alice).
sister(alice, claude).
sister(florence, edward).
sister(florence, edward).
sister(florence, edward).
sister(florence, grace).
sister(florence, grace).
sister(florence, grace).
sister(grace, edward).
sister(grace, edward).
sister(grace, edward).
sister(grace, florence).
sister(grace, florence).
sister(grace, florence).

sibling(One, Another) :- brother(One, Another); sister(One, Another).
wife(Woman, Man) :- husband(Man, Woman).
mother(Ancestor, Descendent) :- father(Man, Descendent), wife(Ancestor, Man).
parent(Ancestor, Descendent) :- father(Ancestor, Descendent); mother(Ancestor, Descendent).
aunt(Woman, Descendent) :- parent(Ancestor, Descendent), sister(Woman, Ancestor).
aunt(Woman, Descendent) :- parent(Ancestor, Descendent), brother(Husband, Ancestor), wife(Woman, Husband).
uncle(Man, Descendent) :- parent(Ancestor, Descendent), brother(Man, Ancestor).
uncle(Man, Descendent) :- parent(Ancestor, Descendent), sister(Wife, Ancestor), husband(Man, Wife).
grandfather(Man, Descendent) :- parent(Ancestor, Descendent), father(Man, Ancestor).
grandmother(Woman, Descendent) :- parent(Ancestor, Descendent), mother(Woman, Ancestor).
grandparent(Ancestor, Descendent) :- grandfather(Ancestor, Descendent); grandmother(Ancestor, Descendent).
greataunt(Woman, Descendent) :- parent(Ancestor, Descendent), aunt(Woman, Ancestor).
greatuncle(Man, Descendent) :- parent(Ancestor, Descendent), uncle(Man, Ancestor).
