// Watcher
// April 2010

inherit RoomPlusCode;

void extra_create()
{
    set("short","A Clearing in the Great Swamp");
    set("day_long","You have entered a huge clearing, free of the "
        "putrid water that fills the rest of the swamp. The smells "
        "seem worse and you quickly see why. In the center of the "
        "room, is the decaying corpse of what appears to be a "
        "gigantic troll. It's lower body appears to be stuck into some "
        "kind of bog but you aren't sure. The size of it takes up most "
        "of the area, making it difficult to see past it. There are signs "
        "of a vicious battle having taken place here as there are still "
        "pools and patches of blood and gore surrounding the troll's "
        "corpse. The trees surrounding the corpse are very dense, "
        "but you see several clearings which look to lead back into "
        "the midst of the Great Swamp.");
    set("descs", ([
        ({"blood","gore","pools of blood","pools"}): "There are various "
            "patches of blood and gore surrounding the dead giant "
            "stuck in the bog. No other corpses remain, but judging "
            "from the blood oozing and crusted on the decomposing "
            "body, you do not believe that most of these puddles came "
            "from the troll.",
        ({"bog","quicksand","quag","quagmire"}): "The bog seems "
            "to be a patch of quicksand. The corpse of a gigantic "
            "troll seems to have died after getting stuck in it. You feel "
            "that it would be a very wise decision to avoid it.",
        ({"troll","troll corpse","troll giant","giant","giant troll",
            "giant corpse","corpse","corpse of giant", "corpse of troll",
            "decaying corpse","decaying troll","decaying giant",}):
            "While the fetid smells of the swamp have surrounded "
            "you for some time now, the tainted smells coming from "
            "the decaying corpse causes you to heave. It appears "
            "to have fallen into quicksand but the cause of death "
            "was clearly do to the massive number of wounds it "
            "suffered while held captive. Black-feathered arrows "
            "stick out of it's thick mottled skin. Several spears jut out "
            "at various angles and it's body is filled with gaping "
            "wounds and slashes. It seems to have huddled in on "
            "itself as a last effort to protect it's vulnerable face and "
            "neck. You cannot make out it's grotesque face and it "
            "almost looks as if it is clutching something.",
        ({"wounds","troll's wounds","trolls wounds", "wounds on "
            "corpse","wounds on troll"}): "The various gashes and "
            "gaping cuts appear to have been caused by a wide "
            "variety of slashing weapons. There are also numerous "
            "stab wounds along with dozens of black-feathered "
            "arrows and several spears with broken hafts",
        ({"trees","tree"}):"Trees surround the clearing, obscuring "
                "the swamp.  There are several gaps that lead back "
                "into the swamp.",
     ]) );
    set("exits",([
        "north":"160",
        "south":"069",
        "east":"071",
        "west":"166",
    ]) );
}
