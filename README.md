Millburn High School VEX Team
=============================

![Logo](https://cloud.githubusercontent.com/assets/8312336/8241980/58fd2a8a-15da-11e5-890e-1431c96b34d3.jpg)

We are a robotics team in Millburn High School. This is the repository for the 2015 to 2016 team, consisting of the following people:

`// TODO: add people and their jobs`

Yes, there are a lot of people, which is why anyone can leave if they want to, and you can be kicked off if you repeatedly don't show up. That means you should show up and do something. If you can be replaced by a house plant, then there's something wrong. Unless that house plant is a cactus. They're unbeatable.

We plan on having meetings at least twice a week, although during some months (like September) we will have to go every weekday and Saturday because that's when the busy times are. The times are going to be from 3:30ish to 5:30ish, but athletes have to come from 5:30ish to 7:30ish. That means that you do not have an excuse. If you are sick or something, then stay updated. Software developers on the team can just read the git log to stay up-to-date, but you really should also make sure that you know the ideas we are making. As for hardware developers, you will just have to stay in contact somehow.

> The VEX team may seem like a B team, playing second-fiddle to the FIRST Robotics Team. That's because it is. However, it doesn't have to be- you all can make an amazing robot if you work together and try. Also, don't play the fiddle. It's not the 1600s.

> ~ John Lacy (paraphrased)

That said, you're all probably programmers if you're reading this. Thusly, you need to know a few best practices, such as not using `Thusly` in actual speech. You may be 16 but it's not 1916.

## Best Practices for Software Dev
These are all principles that have been forged by the blood, sweat, and tears of the ancient developers, who forged the base systems we all take for granted. These men and women had to make entire operating systems from scratch, so they learned quickly what the best ways were to avoid having the whole thing turn into a mess. Let's talk about that.

**Note**: some of the original rules were omitted because they did not apply well to what we're doing. After all, these rules are best suited for making an operating system, not robot code.

### The Unix Philosophy
Unix was a very early operating system, and proved highly influential. You can still use Unix commands like `cd` and `grep` on the likes of Mac OS and Linux. Needless to say, Unix became very popular because it had something magical about it, or rather some aspects that all helped to create something amazing. These design principles that the creators of Unix followed are called the `Unix Philosophy`. Let's talk about it.

#### Rule of Modularity

Modularity is the idea that a large system is merely a collection of smaller programs that each do something small. That means that you can easily switch out a single piece for another without breaking how the whole system runs. Also, problems in 1 part of the system do not necessarily break the rest of it. This is particularly useful in operating systems, which are huge.

The way we will write modular code is by having small functions that each do something small (like `go()` or `turn()`) and then chain them together to make a large functions (like `goToBall()`).

For example:
```c++
void go() {
	// TODO: make the robot go forwards
}

Color color() {
	// TODO: find the color that the sensor sees
}

void goToBall() {
	while (color() != yellow)
		go();
}
```
See how clean the code is even though it is faily complex? This is because it's all modular. That means that we can also reuse the same simple functions differently to create different mechanisms.

#### Rule of Clarity
This is something that a lot of early developers have difficulty with because it seems counter-intuitive. Why would I need to make my code look good and readable? It just has to run, right?  Well, it should run. However, it never works the first time. Someone has to debug that code, and it might not be you. Even if it is you, then you'll find it much easier to debug code if it is clear and readable.

For example:
```c++
void foo() {

}

Color bar() {
	// TODO: fix this
}

void baz() {
	while (foo() != yellow)
		bar();
}
```
See what I did? I took the code you just saw above and made the function names wierd, but did you see what else I did? I made a mistake- the foo() and bar() functions are in the wrong order. You can tell because foo() does not return a Color. If I wrote `go() == yellow` then that would obviously be wrong because movement has nothing to do with colors.

How do you make code that is clear and easy to read? I recommend reading the `Zen of Python`.

#### Rule of Composition
There are 2 parts to the software we're working on: autonomous and manual. Instead of having each side work separately, we will all work together to create a set of simple functions that we both can use. Then, we will combine them differently to create different software. This way, neither team has to reinvent the wheel, maximizing efficiency.

#### Rule of Economy
> Developers should value developer time over machine time, because machine cycles today are relatively inexpensive compared to prices in the 1970s. This rule aims to reduce development costs of projects

I'm sure you'll be glad to hear this rule because it basically says that you do not have to write efficient code, right? Wrong- it means that you are to write code that is efficient enough. Do not try to go for saving a few bytes of data- that @AbhinavMadahar's job. Just write clear code that works well or is easily fixable if it doesn't work well.
