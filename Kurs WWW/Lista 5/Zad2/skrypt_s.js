var __extends = (this && this.__extends) || function (d, b) {
        for (var p in b) if (b.hasOwnProperty(p)) d[p] = b[p];
        function __() { this.constructor = d; }
        d.prototype = b === null ? Object.create(b) : (__.prototype = b.prototype, new __());
    };
var Vehicle = (function () {
    function Vehicle(curPos, fueCons, tanStat) {
        if (new .target === Vehicle) {
            throw new TypeError("Cannot construct Abstract instances directly");
        }
        if (fueCons < 0) {
            throw new TypeError('value of fuelConsumption needs to be bigger than 0');
        }
        if (tanStat < 0) {
            throw new TypeError('value of tankStatus needs to be bigger than 0');
        }
        this.currentPosition = curPos;
        this.fuelConsumption = fueCons;
        this.tankStatus = tanStat;
    }
    Object.defineProperty(Vehicle.prototype, "_currentPosition", {
        get: function () {
            return this.currentPosition;
        },
        set: function (value) {
            if (value < 0) {
                console.log("We do not support undead animals");
            }
            this.currentPosition = value;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(Vehicle.prototype, "_fuelConsumption", {
        get: function () {
            return this.fuelConsumption;
        },
        set: function (value) {
            this.fuelConsumption = value;
        },
        enumerable: true,
        configurable: true
    });
    Object.defineProperty(Vehicle.prototype, "_tankStatus", {
        get: function () {
            return this.tankStatus;
        },
        set: function (value) {
            this.tankStatus = value;
        },
        enumerable: true,
        configurable: true
    });
    Vehicle.prototype.loadFuel = function (fuel) {
        if (fuel < 0) {
            alert("More than 0!");
        }
        this.tankStatus += fuel;
    };
    Vehicle.prototype.move = function (x, y) {
        var count = x + y;
        if (count * this.fuelConsumption > this.tankStatus) {
            alert("Need fuel to move!");
        }
        else {
            this.currentPosition += count;
            this.tankStatus -= count * this.fuelConsumption;
        }
    };
    return Vehicle;
}());
var Car = (function (_super) {
    __extends(Car, _super);
    function Car(curPos, fueCons, tanStat) {
        _super.call(this, curPos, fueCons, tanStat);
    }
    Car.prototype.description = function () {
        return "<img id='car' src='car.png'> This is CAR - Tank status : " + this.tankStatus + " Fuel consumption : " + this.fuelConsumption + " Current position : " + this.currentPosition;
    };
    return Car;
}(Vehicle));
var Truck = (function (_super) {
    __extends(Truck, _super);
    function Truck(curPos, fueCons, tanStat) {
        _super.call(this, curPos, fueCons, tanStat);
    }
    Truck.prototype.description = function () {
        return "<img id='truck' src='truck.png'> This is TRUCK - Tank status : " + this.tankStatus + " Fuel consumption : " + this.fuelConsumption + " Current position : " + this.currentPosition;
    };
    return Truck;
}(Vehicle));
//# sourceMappingURL=test.js.map

var truck;
var car;

function createVehicle() {

    var veh = new Vehicle(0, 15, 150);
    
}

function createCar() {

    car = new Car(0, 15, 150);

    document.getElementById("statusBarForCar").innerHTML = car.description();
    document.getElementById("menuCar").style.display = "block";

}

function createTruck() {

    truck = new Truck(0, 15, 150);

    document.getElementById("statusBarForTruck").innerHTML = truck.description();
    document.getElementById("menuTruck").style.display = "block";
}


function loadFuelCar() {

    car.loadFuel(1);

    document.getElementById("statusBarForCar").innerHTML = car.description();

}

function loadFuelTruck() {

    truck.loadFuel(1);

    document.getElementById("statusBarForTruck").innerHTML = truck.description();

}


function moveCar() {

    car.move(1,0);

    document.getElementById("statusBarForCar").innerHTML = car.description();

}

function moveTruck() {

    truck.move(1,0);

    document.getElementById("statusBarForTruck").innerHTML = truck.description();

}